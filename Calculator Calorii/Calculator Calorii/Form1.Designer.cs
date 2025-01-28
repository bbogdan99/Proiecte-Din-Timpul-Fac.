namespace Calculator_Calorii
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.BMI = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.Tip_Activitate = new System.Windows.Forms.CheckedListBox();
            this.F = new System.Windows.Forms.RadioButton();
            this.Greutate = new System.Windows.Forms.TextBox();
            this.M = new System.Windows.Forms.RadioButton();
            this.label5 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.Inaltime = new System.Windows.Forms.TextBox();
            this.Varsta = new System.Windows.Forms.TextBox();
            this.BMI_Afis = new System.Windows.Forms.TextBox();
            this.Calorii_Afis = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.Slabit = new System.Windows.Forms.Button();
            this.Mentinere = new System.Windows.Forms.Button();
            this.Masa = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label8 = new System.Windows.Forms.Label();
            this.Comentarii = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // BMI
            // 
            this.BMI.Location = new System.Drawing.Point(18, 30);
            this.BMI.Name = "BMI";
            this.BMI.Size = new System.Drawing.Size(272, 29);
            this.BMI.TabIndex = 0;
            this.BMI.Text = "Calculeaza BMI";
            this.BMI.UseVisualStyleBackColor = true;
            this.BMI.Click += new System.EventHandler(this.BMI_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.Tip_Activitate);
            this.groupBox1.Controls.Add(this.F);
            this.groupBox1.Controls.Add(this.Greutate);
            this.groupBox1.Controls.Add(this.M);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.Inaltime);
            this.groupBox1.Controls.Add(this.Varsta);
            this.groupBox1.Location = new System.Drawing.Point(17, 22);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(328, 323);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Informatii";
            // 
            // Tip_Activitate
            // 
            this.Tip_Activitate.FormattingEnabled = true;
            this.Tip_Activitate.Items.AddRange(new object[] {
            "Sedentara",
            "Moderata",
            "Activ",
            "Foarte activ"});
            this.Tip_Activitate.Location = new System.Drawing.Point(151, 204);
            this.Tip_Activitate.Name = "Tip_Activitate";
            this.Tip_Activitate.Size = new System.Drawing.Size(119, 92);
            this.Tip_Activitate.TabIndex = 7;
            this.Tip_Activitate.SelectedIndexChanged += new System.EventHandler(this.Tip_Activitate_SelectedIndexChanged);
            // 
            // F
            // 
            this.F.AutoSize = true;
            this.F.Location = new System.Drawing.Point(233, 74);
            this.F.Name = "F";
            this.F.Size = new System.Drawing.Size(37, 24);
            this.F.TabIndex = 8;
            this.F.TabStop = true;
            this.F.Text = "F";
            this.F.UseVisualStyleBackColor = true;
            this.F.CheckedChanged += new System.EventHandler(this.F_CheckedChanged);
            // 
            // Greutate
            // 
            this.Greutate.Location = new System.Drawing.Point(151, 161);
            this.Greutate.Name = "Greutate";
            this.Greutate.Size = new System.Drawing.Size(119, 27);
            this.Greutate.TabIndex = 3;
            // 
            // M
            // 
            this.M.AutoSize = true;
            this.M.Location = new System.Drawing.Point(151, 74);
            this.M.Name = "M";
            this.M.Size = new System.Drawing.Size(43, 24);
            this.M.TabIndex = 7;
            this.M.TabStop = true;
            this.M.Text = "M";
            this.M.UseVisualStyleBackColor = true;
            this.M.CheckedChanged += new System.EventHandler(this.M_CheckedChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(17, 204);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(128, 20);
            this.label5.TabIndex = 6;
            this.label5.Text = "Tipul de activitate";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(17, 74);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(32, 20);
            this.label2.TabIndex = 3;
            this.label2.Text = "Sex";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(17, 117);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 20);
            this.label3.TabIndex = 4;
            this.label3.Text = "Inaltime";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(17, 161);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(66, 20);
            this.label4.TabIndex = 5;
            this.label4.Text = "Greutate";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 30);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(119, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Varsta (optional)";
            // 
            // Inaltime
            // 
            this.Inaltime.Location = new System.Drawing.Point(151, 117);
            this.Inaltime.Name = "Inaltime";
            this.Inaltime.Size = new System.Drawing.Size(119, 27);
            this.Inaltime.TabIndex = 1;
            // 
            // Varsta
            // 
            this.Varsta.Location = new System.Drawing.Point(151, 30);
            this.Varsta.Name = "Varsta";
            this.Varsta.Size = new System.Drawing.Size(119, 27);
            this.Varsta.TabIndex = 0;
            // 
            // BMI_Afis
            // 
            this.BMI_Afis.Location = new System.Drawing.Point(18, 78);
            this.BMI_Afis.Name = "BMI_Afis";
            this.BMI_Afis.Size = new System.Drawing.Size(272, 27);
            this.BMI_Afis.TabIndex = 3;
            // 
            // Calorii_Afis
            // 
            this.Calorii_Afis.Location = new System.Drawing.Point(165, 42);
            this.Calorii_Afis.Name = "Calorii_Afis";
            this.Calorii_Afis.Size = new System.Drawing.Size(125, 27);
            this.Calorii_Afis.TabIndex = 5;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(138, 203);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(125, 27);
            this.textBox4.TabIndex = 6;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(17, 411);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(698, 20);
            this.label6.TabIndex = 7;
            this.label6.Text = "Nota: pentru slabire, respectiv pus masa s-a calculat raportat la 0,5 kg/saptaman" +
    "a. Valorile se trec intregi";
            this.label6.Click += new System.EventHandler(this.label6_Click);
            // 
            // Slabit
            // 
            this.Slabit.Location = new System.Drawing.Point(18, 40);
            this.Slabit.Name = "Slabit";
            this.Slabit.Size = new System.Drawing.Size(131, 29);
            this.Slabit.TabIndex = 8;
            this.Slabit.Text = "Pentru slabit";
            this.Slabit.UseVisualStyleBackColor = true;
            this.Slabit.Click += new System.EventHandler(this.Slabit_Click);
            // 
            // Mentinere
            // 
            this.Mentinere.Location = new System.Drawing.Point(18, 87);
            this.Mentinere.Name = "Mentinere";
            this.Mentinere.Size = new System.Drawing.Size(132, 29);
            this.Mentinere.TabIndex = 9;
            this.Mentinere.Text = "Pentru mentinere";
            this.Mentinere.UseVisualStyleBackColor = true;
            this.Mentinere.Click += new System.EventHandler(this.Mentinere_Click);
            // 
            // Masa
            // 
            this.Masa.Location = new System.Drawing.Point(18, 132);
            this.Masa.Name = "Masa";
            this.Masa.Size = new System.Drawing.Size(131, 29);
            this.Masa.TabIndex = 10;
            this.Masa.Text = "Pentru pus masa";
            this.Masa.UseVisualStyleBackColor = true;
            this.Masa.Click += new System.EventHandler(this.Masa_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.BMI);
            this.groupBox2.Controls.Add(this.BMI_Afis);
            this.groupBox2.Location = new System.Drawing.Point(367, 22);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(302, 125);
            this.groupBox2.TabIndex = 11;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "BMI";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(18, 78);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(0, 20);
            this.label7.TabIndex = 4;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.textBox4);
            this.groupBox3.Controls.Add(this.Slabit);
            this.groupBox3.Controls.Add(this.Mentinere);
            this.groupBox3.Controls.Add(this.Calorii_Afis);
            this.groupBox3.Controls.Add(this.Masa);
            this.groupBox3.Location = new System.Drawing.Point(367, 166);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(302, 179);
            this.groupBox3.TabIndex = 13;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Calculator calorii";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(17, 369);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(175, 20);
            this.label8.TabIndex = 14;
            this.label8.Text = "Comentarii suplimentare:";
            // 
            // Comentarii
            // 
            this.Comentarii.Location = new System.Drawing.Point(198, 369);
            this.Comentarii.Name = "Comentarii";
            this.Comentarii.Size = new System.Drawing.Size(471, 27);
            this.Comentarii.TabIndex = 15;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(694, 369);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(94, 29);
            this.button1.TabIndex = 16;
            this.button1.Text = "Help";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.Comentarii);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button BMI;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckedListBox Tip_Activitate;
        private System.Windows.Forms.RadioButton F;
        private System.Windows.Forms.TextBox Greutate;
        private System.Windows.Forms.RadioButton M;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox Inaltime;
        private System.Windows.Forms.TextBox Varsta;
        private System.Windows.Forms.TextBox BMI_Afis;
        private System.Windows.Forms.TextBox Calorii_Afis;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button Slabit;
        private System.Windows.Forms.Button Mentinere;
        private System.Windows.Forms.Button Masa;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox Comentarii;
        private System.Windows.Forms.Button button1;
    }
}

