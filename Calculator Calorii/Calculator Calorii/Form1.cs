using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator_Calorii
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void BMI_Click(object sender, EventArgs e) //calcularea BMI ului
        {


            int x = 0, y = 0;
            //verificari daca au fost introduse sau nu numere in locurile cheie
            if (!Int32.TryParse(Inaltime.Text, out x))
            {
                if (!Int32.TryParse(Greutate.Text, out y))
                    Comentarii.Text = "Greutatea si inaltimea introdusa treubie sa fie numere!";
                else Comentarii.Text = "Inaltimea introdusa trebuie sa fie numar!";
            }
            else if (!Int32.TryParse(Greutate.Text, out y))
                Comentarii.Text = "Greutatea introdusa trebuie sa fie numar!";
            else
            {
                Int32.TryParse(Inaltime.Text, out x);
                Int32.TryParse(Greutate.Text, out y);

                if (x < 150 || x > 240) //verificari valori reale pentru inaltime, respectiv greutate
                {
                    if (y < 40 || y > 200)
                    {
                        Comentarii.Text = "Valorile pentru inaltime trebuie sa fie cuprinse intre 150 cm, si 240 cm, iar pentru greutate intre 40 si 200 kg";
                    }
                    Comentarii.Text = "Valorile pentru inaltime trebuie sa fie cuprinse intre 150 cm, si 240 cm";
                }
                else if (y < 40 || y > 200)
                    Comentarii.Text = "Valoarile pentru greutate trebuie sa fie cuprinse intre 40 si 200 kg";
                else
                {
                    float xtemp = y;
                    float ytemp = x * x;

                    float bmi = xtemp / ytemp * 10000; //formula specifica

                    //float bmi = ((float)(x)  / (float)(y * y)) * 1000;
                    if (bmi < 18.5) //situatia persoanei
                        BMI_Afis.Text = bmi.ToString() + " - Subponderal (<18.5)";
                    if (bmi > 18.5 && bmi < 24.9)
                        BMI_Afis.Text = bmi.ToString() + " - Normal (>18.5, <24.9)";
                    if (bmi > 24.9 && bmi < 29.9)
                        BMI_Afis.Text = bmi.ToString() + " - Supraponderal (>24.9, <29.9)";
                    if (bmi > 29.9 && bmi < 34.9)
                        BMI_Afis.Text = bmi.ToString() + " - Obez (>29.9, <34.9)";

                    //BMI_Afis.Text = x.ToString() + " " + y.ToString();

                }
            }
        }

        private void M_CheckedChanged(object sender, EventArgs e) //schimbarea butonului F din check in unchecked
        {
            if (M.Checked == true)
                F.Checked = false;
        }

        private void F_CheckedChanged(object sender, EventArgs e) //schimbarea butonuui M din check in unchecked
        {
            if (F.Checked == true)
                M.Checked = false;
        }

        private void Tip_Activitate_SelectedIndexChanged(object sender, EventArgs e) //schimbarea state-ului pentru butoanele de activitate
        {
            if (Tip_Activitate.GetSelected(0) == true)
            {
                Tip_Activitate.SetItemCheckState(0, CheckState.Checked);
                Tip_Activitate.SetItemCheckState(1, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(2, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(3, CheckState.Unchecked);
            }
            if (Tip_Activitate.GetSelected(1) == true)
            {
                Tip_Activitate.SetItemCheckState(0, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(1, CheckState.Checked);
                Tip_Activitate.SetItemCheckState(2, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(3, CheckState.Unchecked);
            }
            if (Tip_Activitate.GetSelected(2) == true)
            {
                Tip_Activitate.SetItemCheckState(0, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(1, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(2, CheckState.Checked);
                Tip_Activitate.SetItemCheckState(3, CheckState.Unchecked);
            }
            if (Tip_Activitate.GetSelected(3) == true)
            {
                Tip_Activitate.SetItemCheckState(0, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(1, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(2, CheckState.Unchecked);
                Tip_Activitate.SetItemCheckState(3, CheckState.Checked);
            }

        }

        private void Slabit_Click(object sender, EventArgs e) //calcularea caloriilor necesare pentru a slabi
        {
            int x = 0;
            int y = -1;
            if (!Int32.TryParse(Greutate.Text, out x)) //verific daca a fost introdus un numar sau nu
                Comentarii.Text = "Introduceti valori pentru greutate (intre 40 si 200 kg) pentru calculul caloric!";
            if (Tip_Activitate.GetItemChecked(0) == true) //tipul activitatii
                y = 0;
            if (Tip_Activitate.GetItemChecked(1) == true)
                y = 1;
            if (Tip_Activitate.GetItemChecked(2) == true)
                y = 2;
            if (Tip_Activitate.GetItemChecked(3) == true)
                y = 3;

            if (y == -1) //nu a fost aleasa nicio activitate
                Comentarii.Text = "Alegeti tipul de activitate desfasurat in decursul saptamanii!";

            
            float calorii = x * 31; //formula specifica

            if (y == 1) //cu adaus sau nu in functie de tipul activitatii
                calorii = calorii + 200;
            else if (y == 2)
                calorii = calorii + 500;
            else if (y == 3)
                calorii = calorii + 1000;

            if (M.Checked == true) //cu adaus sau scadere in functie de sex
                calorii = calorii - 200;
            if (F.Checked == true)
                calorii = calorii + 200;

            calorii = calorii - 500;
            int a;
            if (Int32.TryParse(Varsta.Text, out a))
                Int32.TryParse(Varsta.Text, out a);
            if (a < 18 && a != 0) //cu adaus sau nu in functie de varsta
                calorii = calorii + 300;
            Calorii_Afis.Text = calorii.ToString();

        }

        private void Mentinere_Click(object sender, EventArgs e) //calcularea caloriilor necesare pentru a se mentine greutatea
        {
            int x = 0;
            int y = -1;
            if (!Int32.TryParse(Greutate.Text, out x)) //verific daca a fost introdus un numar sau nu
                Comentarii.Text = "Introduceti valori pentru greutate (intre 40 si 200 kg) pentru calculul caloric!";
            if (Tip_Activitate.GetItemChecked(0) == true) //tipul de activitate selectat
                y = 0;
            if (Tip_Activitate.GetItemChecked(1) == true)
                y = 1;
            if (Tip_Activitate.GetItemChecked(2) == true)
                y = 2;
            if (Tip_Activitate.GetItemChecked(3) == true)
                y = 3;

            if (y == -1) //nu a fost selectat nimic
                Comentarii.Text = "Alegeti tipul de activitate desfasurat in decursul saptamanii!";


            float calorii = x * 31; //formula specifica

            if (y == 1) //adaus sau scazut in functie de tipul activitatii alese
                calorii = calorii + 200;
            else if (y == 2)
                calorii = calorii + 500;
            else if (y == 3)
                calorii = calorii + 1000;

            if (M.Checked == true)
                calorii = calorii - 200;
            if (F.Checked == true)
                calorii = calorii + 200;

            calorii = calorii - 0;
            int a;
            if (Int32.TryParse(Varsta.Text, out a))
                Int32.TryParse(Varsta.Text, out a);
            if (a < 18 && a != 0) //adaus sau nu in functie de varsta
                calorii = calorii + 300;
            Calorii_Afis.Text = calorii.ToString();

        }

        private void Masa_Click(object sender, EventArgs e) //calcularea caloriilor necesare pentru a pune masa
        {
            int x = 0;
            int y = -1;
            if (!Int32.TryParse(Greutate.Text, out x)) //verifica daca a fost introdus un numar
                Comentarii.Text = "Introduceti valori pentru greutate (intre 40 si 200 kg) pentru calculul caloric!";
            if (Tip_Activitate.GetItemChecked(0) == true) //tipurile de activitate
                y = 0;
            if (Tip_Activitate.GetItemChecked(1) == true)
                y = 1;
            if (Tip_Activitate.GetItemChecked(2) == true)
                y = 2;
            if (Tip_Activitate.GetItemChecked(3) == true)
                y = 3;

            if (y == -1) //nu s-a ales nicio activitate
                Comentarii.Text = "Alegeti tipul de activitate desfasurat in decursul saptamanii!";


            float calorii = x * 31; //formula specifica, cu adaus sau nu in functie de tip (y)

            if (y == 1)
                calorii = calorii + 200;
            else if (y == 2)
                calorii = calorii + 500;
            else if (y == 3)
                calorii = calorii + 1000;

            if (M.Checked == true) //adaus sau scazut in functie de sex
                calorii = calorii - 200;
            if (F.Checked == true)
                calorii = calorii + 200;

            calorii = calorii + 300;
            int a; //adaus sau scazut in functie de varsta (sub 18 ani sau nu)
            if (Int32.TryParse(Varsta.Text, out a))
                Int32.TryParse(Varsta.Text, out a);
            if (a < 18 && a != 0)
                calorii = calorii + 300;
            Calorii_Afis.Text = calorii.ToString();

        }

        private void button1_Click(object sender, EventArgs e) //butonul de help
        {
            Help.ShowHelp(this, "help.chm");
            //Help.ShowHelp(this, "file://c:\\help.chm");
            //System.Diagnostics.Process.Start(@"c:\help.chm");
            //Help.ShowHelp(this, "help.chm");
            //System.Diagnostics.Process.Start("file://c:\\help.chm");
        }
    }
}
