/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  FREQ_PANEL                       1       /* callback function: OnMainPanel */
#define  FREQ_PANEL_IDC_SWITCH_PANEL      2       /* control type: binary, callback function: OnSwitchPanelCB */
#define  FREQ_PANEL_IDC_GRAPH_DATA        3       /* control type: graph, callback function: (none) */
#define  FREQ_PANEL_FREQ_PEAK             4       /* control type: numeric, callback function: (none) */
#define  FREQ_PANEL_POWER_PEAK            5       /* control type: numeric, callback function: (none) */
#define  FREQ_PANEL_SPECTRU               6       /* control type: command, callback function: OnSpectru */
#define  FREQ_PANEL_NUMAR_PUNCTE          7       /* control type: numeric, callback function: (none) */
#define  FREQ_PANEL_SPECTRU2              8       /* control type: command, callback function: OnSpectru2 */

#define  PANEL                            2       /* callback function: OnMainPanel */
#define  PANEL_IDC_GRAPH_RAW_DATA         2       /* control type: graph, callback function: (none) */
#define  PANEL_GRAPH_2                    3       /* control type: graph, callback function: (none) */
#define  PANEL_PREV                       4       /* control type: command, callback function: OnPrev */
#define  PANEL_NEXT                       5       /* control type: command, callback function: OnNext */
#define  PANEL_APLICA                     6       /* control type: command, callback function: OnAplica */
#define  PANEL_LOAD_WAVE_FILE             7       /* control type: command, callback function: OnLoadButtonCB */
#define  PANEL_START                      8       /* control type: numeric, callback function: OnStart */
#define  PANEL_STOP                       9       /* control type: numeric, callback function: OnStop */
#define  PANEL_Mean                       10      /* control type: numeric, callback function: OnMean */
#define  PANEL_FILTRU                     11      /* control type: ring, callback function: OnFiltru */
#define  PANEL_TEXTMSG                    12      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_3                  13      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_2                  14      /* control type: textMsg, callback function: (none) */
#define  PANEL_TEXTMSG_4                  15      /* control type: textMsg, callback function: (none) */
#define  PANEL_Max                        16      /* control type: numeric, callback function: (none) */
#define  PANEL_Min                        17      /* control type: numeric, callback function: (none) */
#define  PANEL_MaxIndex                   18      /* control type: numeric, callback function: (none) */
#define  PANEL_MinIndex                   19      /* control type: numeric, callback function: (none) */
#define  PANEL_StdDev                     20      /* control type: numeric, callback function: (none) */
#define  PANEL_Mediana                    21      /* control type: numeric, callback function: (none) */
#define  PANEL_ALPHA                      22      /* control type: numeric, callback function: OnAlpha */
#define  PANEL_ANVELOPA                   23      /* control type: command, callback function: OnAnvelopa */
#define  PANEL_MEDIERE                    24      /* control type: ring, callback function: OnMediere */
#define  PANEL_Zero                       25      /* control type: numeric, callback function: (none) */
#define  PANEL_HISTOGRAM                  26      /* control type: graph, callback function: (none) */
#define  PANEL_IDC_SWITCH_PANEL           27      /* control type: binary, callback function: OnSwitchPanelCB */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK OnAlpha(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnAnvelopa(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnAplica(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnFiltru(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnLoadButtonCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnMainPanel(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnMean(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnMediere(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnNext(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnPrev(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnSpectru(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnSpectru2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnStart(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnStop(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK OnSwitchPanelCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
