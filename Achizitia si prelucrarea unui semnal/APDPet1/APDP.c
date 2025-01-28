#include <analysis.h>
#include <utility.h>
#include <formatio.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "APDP.h"

#define SAMPLE_RATE 0
#define NPOINTS 1

int waveInfo[2];

double sampleRate = 0.0;

int npoints = 0;

double *waveData = 0;

double *envelope = 0;

double df=0.0; 
double freqPeak=0.0; 
double powerPeak=0.0;


static int panelHandle;

static int freqPanel;

int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "APDP.uir", PANEL)) < 0)
		return -1;
	
	if ((freqPanel = LoadPanel (0, "APDP.uir", FREQ_PANEL)) < 0)
		return -1;
	
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK OnSpectru2 (int panel, int control, int event,
									 void *callbackData, int eventData1, int eventData2)
{
	double Nt;
	int N;
	GetCtrlVal(freqPanel,FREQ_PANEL_NUMAR_PUNCTE, &Nt);
	N = (int)Nt;
	WindowConst winConst;
	double convertedSpectrum[N/2];
	double autoSpectrum[N/2]; 
	 
	
	char unit[32]="V"; 
	
	switch (event)
	{
		case EVENT_COMMIT:

		int imageHandle;
		
		ScaledWindowEx (waveData,N, BLKMAN, 0, &winConst);
		AutoPowerSpectrum(waveData,N, 1.0/N, autoSpectrum, &df);
		PowerFrequencyEstimate(autoSpectrum,N/2,-1,winConst,df,7,&freqPeak,&powerPeak);
		
		SetCtrlVal(freqPanel,FREQ_PANEL_FREQ_PEAK,freqPeak);
		SetCtrlVal(freqPanel,FREQ_PANEL_POWER_PEAK,powerPeak);
		
		SpectrumUnitConversion(autoSpectrum, N/2,SPECTRUM_POWER, SCALING_MODE_LINEAR, DISPLAY_UNIT_VRMS, df, winConst, convertedSpectrum, unit);
		DeleteGraphPlot(panel,FREQ_PANEL_IDC_GRAPH_DATA,-1,VAL_IMMEDIATE_DRAW);
		PlotWaveform(panel,  FREQ_PANEL_IDC_GRAPH_DATA, convertedSpectrum, N /4 ,VAL_DOUBLE, 1.0, 0.0, 0.0,
					 df,VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID,  VAL_CONNECTED_POINTS, VAL_RED);
		
		GetCtrlDisplayBitmap(panel, FREQ_PANEL_IDC_GRAPH_DATA, 1, &imageHandle);
        SaveBitmapToJPEGFile(imageHandle, "Spectru1.jpeg",JPEG_PROGRESSIVE, 100);
        DiscardBitmap(imageHandle);
		
		break;
	}
	return 0;
}

int CVICALLBACK OnSpectru (int panel, int control, int event,
									 void *callbackData, int eventData1, int eventData2)
{
	double Nt;
	int N;
	GetCtrlVal(freqPanel,FREQ_PANEL_NUMAR_PUNCTE, &Nt);
	N = (int)Nt;
	WindowConst winConst;
	double convertedSpectrum[N/2];
	double autoSpectrum[N/2]; 
	 
	
	char unit[32]="V"; 
	
	switch (event)
	{
		case EVENT_COMMIT:

		int imageHandle;
		
		ScaledWindowEx (waveData,N, FLATTOP, 0, &winConst);
		AutoPowerSpectrum(waveData,N, 1.0/N, autoSpectrum, &df);
		PowerFrequencyEstimate(autoSpectrum,N/2,-1,winConst,df,7,&freqPeak,&powerPeak);
		
		SetCtrlVal(freqPanel,FREQ_PANEL_FREQ_PEAK,freqPeak);
		SetCtrlVal(freqPanel,FREQ_PANEL_POWER_PEAK,powerPeak);
		
		SpectrumUnitConversion(autoSpectrum, N/2,SPECTRUM_POWER, SCALING_MODE_LINEAR, DISPLAY_UNIT_VRMS, df, winConst, convertedSpectrum, unit);
		DeleteGraphPlot(panel,FREQ_PANEL_IDC_GRAPH_DATA,-1,VAL_IMMEDIATE_DRAW);
		PlotWaveform(panel,  FREQ_PANEL_IDC_GRAPH_DATA, convertedSpectrum, N /4 ,VAL_DOUBLE, 1.0, 0.0, 0.0,
					 df,VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID,  VAL_CONNECTED_POINTS, VAL_RED);
		
		GetCtrlDisplayBitmap(panel, FREQ_PANEL_IDC_GRAPH_DATA, 1, &imageHandle);
        SaveBitmapToJPEGFile(imageHandle, "Spectru1.jpeg",JPEG_PROGRESSIVE, 100);
        DiscardBitmap(imageHandle);
		
		break;
	}
	return 0;
}

int CVICALLBACK OnSwitchPanelCB (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(panel == panelHandle)
			{
				SetCtrlVal(freqPanel, FREQ_PANEL_IDC_SWITCH_PANEL, 1);
				DisplayPanel(freqPanel);
				HidePanel(panel);
			}
			else
			{
				SetCtrlVal(panelHandle, PANEL_IDC_SWITCH_PANEL, 0);
				DisplayPanel(panelHandle);
				HidePanel(panel);
			}
			break;
			
			
	}
	return 0;

}


int CVICALLBACK OnMainPanel (int panel, int event, void *callbackData,
							 int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface(0);
			break;
	}
	return 0;
}

int CVICALLBACK OnPrev (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			int start, stop;
			
			GetCtrlVal(panel, PANEL_START, &start);
			GetCtrlVal(panel, PANEL_STOP, &stop);
			
			if (start!=0)
			{
				start--;stop--;
			}
			
			SetCtrlVal(panel, PANEL_START, start);
			SetCtrlVal(panel, PANEL_STOP, stop);
			
			int filtru;
			double* flit = 0;
			flit = (double *) calloc(npoints, sizeof(double));
			double alpha;
			GetCtrlVal(panel, PANEL_ALPHA, &alpha);
			GetCtrlVal(panel, PANEL_FILTRU, &filtru);
			
			GetCtrlVal(panel, PANEL_START, &start);
			
			
			if (alpha>=1)
			{
				alpha=0.99;
				SetCtrlVal(panel,PANEL_ALPHA, alpha);
			}
			if (alpha<=0)
			{
				alpha=0.01;
				SetCtrlVal(panel,PANEL_ALPHA, alpha);
			}
			
			if (filtru ==1)
			{
				//8,16,32
				
				int mediere;
				GetCtrlVal(panel, PANEL_MEDIERE, &mediere);
				
				MedianFilter(waveData, npoints, mediere, 0, flit);
				DeleteGraphPlot(panel, PANEL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
				
				/*
				PlotY(panel, PANEL_GRAPH_2, flit, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				*/
				
				double* flitSect = 0;
				flitSect = (double *)calloc (sampleRate, sizeof(double));
				int x;
				x= (int)start*sampleRate;
				for (int i=0; i<sampleRate;i++)
					flitSect[i]=flit[i + x];
				
				double* waveDataSect = 0;								
				waveDataSect = (double *)calloc(sampleRate, sizeof(double));
				for (int j=0;j<sampleRate;j++)
					waveDataSect[j]=waveData[j + x];
				
				DeleteGraphPlot(panel, PANEL_IDC_GRAPH_RAW_DATA, -1, VAL_IMMEDIATE_DRAW);
				PlotY(panel, PANEL_IDC_GRAPH_RAW_DATA, waveDataSect, sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				
				PlotY(panel, PANEL_GRAPH_2, flitSect , sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				ArrayToFile("Salvare1sec", flitSect, VAL_DOUBLE, sampleRate, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_SEP_BY_COMMA, VAL_CONST_WIDTH ,VAL_ASCII, VAL_TRUNCATE);
			}
			if (filtru ==2)
			{
				flit[0]=alpha*waveData[0];
				for (int i=1;i<npoints;i++)
				{	
					flit[i]=(1- alpha) * flit[i-1] + alpha * waveData[i];
				}
				
				DeleteGraphPlot(panel, PANEL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
				
				/*
				PlotY(panel, PANEL_GRAPH_2, flit, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				*/
				
				double* flitSect = 0;
				flitSect = (double *)calloc (sampleRate, sizeof(double));
				int x;
				x= (int)start*sampleRate;
				for (int i=0; i<sampleRate;i++)
					flitSect[i]=flit[i + x];
				
				double* waveDataSect = 0;
				waveDataSect = (double *)calloc(sampleRate, sizeof(double));
				for (int j=0;j<sampleRate;j++)
					waveDataSect[j]=waveData[j + x];
				
				DeleteGraphPlot(panel, PANEL_IDC_GRAPH_RAW_DATA, -1, VAL_IMMEDIATE_DRAW);
				PlotY(panel, PANEL_IDC_GRAPH_RAW_DATA, waveDataSect, sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				
				
				PlotY(panel, PANEL_GRAPH_2, flitSect , sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				ArrayToFile("Salvare1sec", flitSect, VAL_DOUBLE, sampleRate, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_SEP_BY_COMMA, VAL_CONST_WIDTH ,VAL_ASCII, VAL_TRUNCATE);
			}
			
			
			break;
	}
	return 0;
}

int CVICALLBACK OnStart (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK OnStop (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK OnNext (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int start, stop;
			int sec;
			sec = (int)npoints/sampleRate ;
			
			GetCtrlVal(panel, PANEL_START, &start);
			GetCtrlVal(panel, PANEL_STOP, &stop);
			
			if (stop!=sec)
			{
				start++;stop++;
			}
			
			SetCtrlVal(panel, PANEL_START, start);
			SetCtrlVal(panel, PANEL_STOP, stop);
			
			
			int filtru;
			double* flit = 0;
			flit = (double *) calloc(npoints, sizeof(double));
			double alpha;
			GetCtrlVal(panel, PANEL_ALPHA, &alpha);
			GetCtrlVal(panel, PANEL_FILTRU, &filtru);
			
			GetCtrlVal(panel, PANEL_START, &start);
			
			
			if (alpha>=1)
			{
				alpha=0.99;
				SetCtrlVal(panel,PANEL_ALPHA, alpha);
			}
			if (alpha<=0)
			{
				alpha=0.01;
				SetCtrlVal(panel,PANEL_ALPHA, alpha);
			}
			
			if (filtru ==1)
			{
				//8,16,32
				
				int mediere;
				GetCtrlVal(panel, PANEL_MEDIERE, &mediere);
				
				MedianFilter(waveData, npoints, mediere, 0, flit);
				DeleteGraphPlot(panel, PANEL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
				
				/*
				PlotY(panel, PANEL_GRAPH_2, flit, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				*/
				
				double* flitSect = 0;
				flitSect = (double *)calloc (sampleRate, sizeof(double));
				int x;
				x= (int)start*sampleRate;
				for (int i=0; i<sampleRate;i++)
					flitSect[i]=flit[i + x];
				
				double* waveDataSect = 0;
				waveDataSect = (double *)calloc(sampleRate, sizeof(double));
				for (int j=0;j<sampleRate;j++)
					waveDataSect[j]=waveData[j + x];
				
				DeleteGraphPlot(panel, PANEL_IDC_GRAPH_RAW_DATA, -1, VAL_IMMEDIATE_DRAW);
				PlotY(panel, PANEL_IDC_GRAPH_RAW_DATA, waveDataSect, sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				
				
				PlotY(panel, PANEL_GRAPH_2, flitSect , sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				ArrayToFile("Salvare1sec", flitSect, VAL_DOUBLE, sampleRate, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_SEP_BY_COMMA, VAL_CONST_WIDTH ,VAL_ASCII, VAL_TRUNCATE);
			}
			if (filtru ==2)
			{
				flit[0]=alpha*waveData[0];
				for (int i=1;i<npoints;i++)
				{	
					flit[i]=(1- alpha) * flit[i-1] + alpha * waveData[i];
				}
				
				DeleteGraphPlot(panel, PANEL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
				
				/*
				PlotY(panel, PANEL_GRAPH_2, flit, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				*/
				
				double* flitSect = 0;
				flitSect = (double *)calloc (sampleRate, sizeof(double));
				int x;
				x= (int)start*sampleRate;
				for (int i=0; i<sampleRate;i++)
					flitSect[i]=flit[i + x];
				
				double* waveDataSect = 0;
				waveDataSect = (double *)calloc(sampleRate, sizeof(double));
				for (int j=0;j<sampleRate;j++)
					waveDataSect[j]=waveData[j + x];
				
				DeleteGraphPlot(panel, PANEL_IDC_GRAPH_RAW_DATA, -1, VAL_IMMEDIATE_DRAW);
				PlotY(panel, PANEL_IDC_GRAPH_RAW_DATA, waveDataSect, sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				
				
				PlotY(panel, PANEL_GRAPH_2, flitSect , sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				ArrayToFile("Salvare1sec", flitSect, VAL_DOUBLE, sampleRate, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_SEP_BY_COMMA, VAL_CONST_WIDTH ,VAL_ASCII, VAL_TRUNCATE);
			}
			
			
			break;
	}
	return 0;
}

int CVICALLBACK OnDimensiuneFereastra (int panel, int control, int event,
									   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK OnAplica (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	int filtru;
	switch (event)
	{
		case EVENT_COMMIT:

			double* flit = 0;
			flit = (double *) calloc(npoints, sizeof(double));
			double alpha;
			GetCtrlVal(panel, PANEL_ALPHA, &alpha);
			GetCtrlVal(panel, PANEL_FILTRU, &filtru);
			
			int start;
			GetCtrlVal(panel, PANEL_START, &start);
			
			
			if (alpha>=1)
			{
				alpha=0.99;
				SetCtrlVal(panel,PANEL_ALPHA, alpha);
			}
			if (alpha<=0)
			{
				alpha=0.01;
				SetCtrlVal(panel,PANEL_ALPHA, alpha);
			}
			
			if (filtru ==1)
			{
				//8,16,32
				
				int mediere;
				GetCtrlVal(panel, PANEL_MEDIERE, &mediere);
				
				MedianFilter(waveData, npoints, mediere, 0, flit);
				DeleteGraphPlot(panel, PANEL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
			
				DeleteGraphPlot(panel, PANEL_IDC_GRAPH_RAW_DATA, -1, VAL_IMMEDIATE_DRAW);
				PlotY(panel, PANEL_IDC_GRAPH_RAW_DATA, waveData, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				
				
				PlotY(panel, PANEL_GRAPH_2, flit, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				
				
				/*double* flitSect = 0;
				flitSect = (double *)calloc (sampleRate, sizeof(double));
				int x;
				x= (int)start*sampleRate;
				for (int i=0; i<sampleRate;i++)
					flitSect[i]=flit[i + x];
				PlotY(panel, PANEL_GRAPH_2, flitSect , sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				ArrayToFile("Salvare1sec", flitSect, VAL_DOUBLE, sampleRate, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_SEP_BY_COMMA, VAL_CONST_WIDTH ,VAL_ASCII, VAL_TRUNCATE);
				*/
			}
			if (filtru ==2)
			{
				flit[0]=alpha*waveData[0];
				for (int i=1;i<npoints;i++)
				{	
					flit[i]=(1- alpha) * flit[i-1] + alpha * waveData[i];
				}
				
				DeleteGraphPlot(panel, PANEL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
				
				DeleteGraphPlot(panel, PANEL_IDC_GRAPH_RAW_DATA, -1, VAL_IMMEDIATE_DRAW);
				PlotY(panel, PANEL_IDC_GRAPH_RAW_DATA, waveData, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				
				
				PlotY(panel, PANEL_GRAPH_2, flit, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				
				
				/*double* flitSect = 0;
				flitSect = (double *)calloc (sampleRate, sizeof(double));
				int x;
				x= (int)start*sampleRate;
				for (int i=0; i<sampleRate;i++)
					flitSect[i]=flit[i + x];
				PlotY(panel, PANEL_GRAPH_2, flitSect , sampleRate, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
				ArrayToFile("Salvare1sec", flitSect, VAL_DOUBLE, sampleRate, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_SEP_BY_COMMA, VAL_CONST_WIDTH ,VAL_ASCII, VAL_TRUNCATE);
				*/
			}
			
			
			
			break;
	}
	return 0;
}

int CVICALLBACK OnFiltru (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK OnLoadButtonCB (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			//executa script python pentru conversia unui fisierului .wav in .txt
			LaunchExecutable("python mainH.py");
			
			//astept sa fie generate cele doua fisiere (modificati timpul daca este necesar
			Delay(4);
			
			//incarc informatiile privind rata de esantionare si numarul de valori
			FileToArray("wafeInfo.txt", waveInfo, VAL_INTEGER, 2, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_ASCII);
			sampleRate = waveInfo[SAMPLE_RATE];
			npoints = waveInfo[NPOINTS];
			
			//alocare memorie pentru numarul de puncte
			waveData = (double *) calloc(npoints, sizeof(double));
			
			//incarcare din fisierul .txt in memorie (vector)
			FileToArray("waveData.txt", waveData, VAL_DOUBLE, npoints, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_ASCII);
			
			//afisare pe grapf
			PlotY(panel, PANEL_IDC_GRAPH_RAW_DATA, waveData, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
			
			//FileToArray("hilbertData.txt", anvelopa, VAL_
			
			
			
			
			
			envelope = (double *) calloc(npoints, sizeof(double));
			
			FileToArray("hilbertData.txt", envelope, VAL_DOUBLE, npoints, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_ASCII);
			
			
			
			
			
			
			double maxVal = 0.0;
			double minVal = 0.0;
			int maxIndex = 0;
			int minIndex = 0;
			double mean = 0.0;
			double median=0.0;
			double stdDev=0.0;
			
			/*
			double* flit = 0;
			flit = (double *) calloc(npoints, sizeof(double));
			double alpha=0.0;
			GetCtrlVal(panel, PANEL_DIMENSIUNE_FEREASTRA, &alpha);
			flit[0]=alpha*waveData[0];
			for (int i=1;i<npoints;i++)
			{	
				flit[i]=(1- alpha) * flit[i-1] + alpha * waveData[i];
			}
			
			*/
			
			
			
			MaxMin1D(waveData, npoints, &maxVal, &maxIndex, &minVal, &minIndex);
			Mean(waveData, npoints, &mean);
			//Histogram=??
			
			//
			double *xArray=0;
			xArray=(double*) calloc (npoints, sizeof(double));
			double *yArray=0;
			yArray=(double*) calloc (npoints, sizeof(double));
			
			int HistogramArray[npoints];
			//HistogramArray=(double*) calloc(npoints, sizeof(double));
			
			Histogram(waveData, npoints, minVal, maxVal, HistogramArray ,xArray , 10);
			for (int i=0;i<10;i++)
				yArray[i] = yArray[i] + (int)HistogramArray[i];
			
			//PlotY(panel, PANEL_GRAPH_2, yArray , 10, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
			//PlotXY(panel, PANEL_GRAPH_2, xArray, yArray, 10, VAL_DOUBLE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
			PlotXY(panel, PANEL_HISTOGRAM, xArray, HistogramArray, 10, VAL_DOUBLE, VAL_SSIZE_T, VAL_VERTICAL_BAR, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			
			
			Median(waveData,npoints, &median);
			StdDev(waveData, npoints, &mean, &stdDev);
			
			SetCtrlVal(panel, PANEL_Mean, mean);
			SetCtrlVal(panel, PANEL_Min, minVal);
			SetCtrlVal(panel, PANEL_Max, maxVal);
			SetCtrlVal(panel, PANEL_MinIndex, (double)minIndex);
			SetCtrlVal(panel, PANEL_MaxIndex, (double)maxIndex);
			SetCtrlVal(panel, PANEL_Mediana, median);
			SetCtrlVal(panel, PANEL_StdDev, stdDev);
			
			//nr de treceri prin zero?
			
			double zero=0;
			for (int k=0;k<npoints-1;k++)
				if (waveData[k] * waveData[k+1] < 0 ) zero++;
			SetCtrlVal(panel, PANEL_Zero, zero);
			
			break;
	}
	return 0;
}

int CVICALLBACK OnMean (int panel, int control, int event,
						void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK OnAlpha (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK OnAnvelopa (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			/*LaunchExecutable("python hilbert.py");
			
			//astept sa fie generate cele doua fisiere (modificati timpul daca este necesar
			Delay(4);
			
			//incarc informatiile privind rata de esantionare si numarul de valori
			FileToArray("hilbertR.txt", waveInfo, VAL_INTEGER, 2, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_ASCII);
			sampleRate = waveInfo[SAMPLE_RATE];
			npoints = waveInfo[NPOINTS];
			
			//alocare memorie pentru numarul de puncte
			waveData = (double *) calloc(npoints, sizeof(double));
			
			//incarcare din fisierul .txt in memorie (vector)
			FileToArray("hilbertRR.txt", waveData, VAL_DOUBLE, npoints, 1, VAL_GROUPS_TOGETHER, VAL_GROUPS_AS_COLUMNS, VAL_ASCII);
			
			//afisare pe grapf
			PlotY(panel, PANEL_IDC_GRAPH_RAW_DATA, waveData, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
			
			*/
			DeleteGraphPlot(panel, PANEL_GRAPH_2, -1, VAL_IMMEDIATE_DRAW);
			PlotY(panel, PANEL_GRAPH_2, envelope, npoints, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, VAL_CONNECTED_POINTS, VAL_RED);
			
			break;
	}
	return 0;
}

int CVICALLBACK OnMediere (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}
