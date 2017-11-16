namespace WindowsFormsApplication6
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.NUD_Height = new System.Windows.Forms.NumericUpDown();
            this.La_Title = new System.Windows.Forms.Label();
            this.PB_Height = new System.Windows.Forms.ProgressBar();
            this.La_HeightTitle = new System.Windows.Forms.Label();
            this.La_WeightTitle = new System.Windows.Forms.Label();
            this.PB_Weight = new System.Windows.Forms.ProgressBar();
            this.NUD_Weight = new System.Windows.Forms.NumericUpDown();
            this.La_Result = new System.Windows.Forms.Label();
            this.La_TezkaPodvyziva = new System.Windows.Forms.Label();
            this.La_Podvaha = new System.Windows.Forms.Label();
            this.La_Nadvaha = new System.Windows.Forms.Label();
            this.La_IdealniVaha = new System.Windows.Forms.Label();
            this.La_Obezita2 = new System.Windows.Forms.Label();
            this.La_Obezita1 = new System.Windows.Forms.Label();
            this.La_Obezita3 = new System.Windows.Forms.Label();
            this.Pa_Content = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Height)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Weight)).BeginInit();
            this.Pa_Content.SuspendLayout();
            this.SuspendLayout();
            // 
            // NUD_Height
            // 
            this.NUD_Height.Increment = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.NUD_Height.Location = new System.Drawing.Point(142, 69);
            this.NUD_Height.Maximum = new decimal(new int[] {
            220,
            0,
            0,
            0});
            this.NUD_Height.Minimum = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.NUD_Height.Name = "NUD_Height";
            this.NUD_Height.Size = new System.Drawing.Size(120, 20);
            this.NUD_Height.TabIndex = 0;
            this.NUD_Height.Value = new decimal(new int[] {
            180,
            0,
            0,
            0});
            this.NUD_Height.ValueChanged += new System.EventHandler(this.NUD_ValueChanged);
            // 
            // La_Title
            // 
            this.La_Title.BackColor = System.Drawing.Color.Transparent;
            this.La_Title.Font = new System.Drawing.Font("Segoe UI", 24F, System.Drawing.FontStyle.Bold);
            this.La_Title.ForeColor = System.Drawing.Color.Black;
            this.La_Title.Location = new System.Drawing.Point(12, 0);
            this.La_Title.Name = "La_Title";
            this.La_Title.Size = new System.Drawing.Size(250, 50);
            this.La_Title.TabIndex = 2;
            this.La_Title.Text = "BMI Calculator";
            this.La_Title.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // PB_Height
            // 
            this.PB_Height.Location = new System.Drawing.Point(20, 69);
            this.PB_Height.Name = "PB_Height";
            this.PB_Height.Size = new System.Drawing.Size(116, 20);
            this.PB_Height.TabIndex = 3;
            // 
            // La_HeightTitle
            // 
            this.La_HeightTitle.AutoSize = true;
            this.La_HeightTitle.BackColor = System.Drawing.Color.Transparent;
            this.La_HeightTitle.Location = new System.Drawing.Point(20, 50);
            this.La_HeightTitle.Name = "La_HeightTitle";
            this.La_HeightTitle.Size = new System.Drawing.Size(91, 13);
            this.La_HeightTitle.TabIndex = 4;
            this.La_HeightTitle.Text = "Zadej výšku [cm]:";
            // 
            // La_WeightTitle
            // 
            this.La_WeightTitle.AutoSize = true;
            this.La_WeightTitle.BackColor = System.Drawing.Color.Transparent;
            this.La_WeightTitle.Location = new System.Drawing.Point(20, 102);
            this.La_WeightTitle.Name = "La_WeightTitle";
            this.La_WeightTitle.Size = new System.Drawing.Size(85, 13);
            this.La_WeightTitle.TabIndex = 7;
            this.La_WeightTitle.Text = "Zadej váhu [kg]:";
            // 
            // PB_Weight
            // 
            this.PB_Weight.Location = new System.Drawing.Point(20, 121);
            this.PB_Weight.Name = "PB_Weight";
            this.PB_Weight.Size = new System.Drawing.Size(116, 20);
            this.PB_Weight.TabIndex = 6;
            // 
            // NUD_Weight
            // 
            this.NUD_Weight.Increment = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.NUD_Weight.Location = new System.Drawing.Point(142, 121);
            this.NUD_Weight.Maximum = new decimal(new int[] {
            160,
            0,
            0,
            0});
            this.NUD_Weight.Minimum = new decimal(new int[] {
            40,
            0,
            0,
            0});
            this.NUD_Weight.Name = "NUD_Weight";
            this.NUD_Weight.Size = new System.Drawing.Size(120, 20);
            this.NUD_Weight.TabIndex = 5;
            this.NUD_Weight.Value = new decimal(new int[] {
            80,
            0,
            0,
            0});
            this.NUD_Weight.ValueChanged += new System.EventHandler(this.NUD_ValueChanged);
            // 
            // La_Result
            // 
            this.La_Result.AutoSize = true;
            this.La_Result.BackColor = System.Drawing.Color.Transparent;
            this.La_Result.Font = new System.Drawing.Font("Microsoft Sans Serif", 17F, System.Drawing.FontStyle.Bold);
            this.La_Result.Location = new System.Drawing.Point(20, 161);
            this.La_Result.Name = "La_Result";
            this.La_Result.Size = new System.Drawing.Size(65, 29);
            this.La_Result.TabIndex = 8;
            this.La_Result.Text = "BMI:";
            // 
            // La_TezkaPodvyziva
            // 
            this.La_TezkaPodvyziva.BackColor = System.Drawing.Color.Transparent;
            this.La_TezkaPodvyziva.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.La_TezkaPodvyziva.Location = new System.Drawing.Point(20, 190);
            this.La_TezkaPodvyziva.Name = "La_TezkaPodvyziva";
            this.La_TezkaPodvyziva.Size = new System.Drawing.Size(242, 29);
            this.La_TezkaPodvyziva.TabIndex = 10;
            this.La_TezkaPodvyziva.Text = "≤ 16,5 těžká podvýživa";
            // 
            // La_Podvaha
            // 
            this.La_Podvaha.BackColor = System.Drawing.Color.Transparent;
            this.La_Podvaha.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.La_Podvaha.Location = new System.Drawing.Point(20, 219);
            this.La_Podvaha.Name = "La_Podvaha";
            this.La_Podvaha.Size = new System.Drawing.Size(242, 29);
            this.La_Podvaha.TabIndex = 11;
            this.La_Podvaha.Text = "16,5–18,5 podváha";
            // 
            // La_Nadvaha
            // 
            this.La_Nadvaha.BackColor = System.Drawing.Color.Transparent;
            this.La_Nadvaha.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.La_Nadvaha.Location = new System.Drawing.Point(20, 277);
            this.La_Nadvaha.Name = "La_Nadvaha";
            this.La_Nadvaha.Size = new System.Drawing.Size(242, 29);
            this.La_Nadvaha.TabIndex = 13;
            this.La_Nadvaha.Text = "25–30 nadváha";
            // 
            // La_IdealniVaha
            // 
            this.La_IdealniVaha.BackColor = System.Drawing.Color.Transparent;
            this.La_IdealniVaha.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.La_IdealniVaha.Location = new System.Drawing.Point(20, 248);
            this.La_IdealniVaha.Name = "La_IdealniVaha";
            this.La_IdealniVaha.Size = new System.Drawing.Size(242, 29);
            this.La_IdealniVaha.TabIndex = 12;
            this.La_IdealniVaha.Text = "18,5–25 ideální (zdravá) váha";
            // 
            // La_Obezita2
            // 
            this.La_Obezita2.BackColor = System.Drawing.Color.Transparent;
            this.La_Obezita2.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.La_Obezita2.Location = new System.Drawing.Point(20, 335);
            this.La_Obezita2.Name = "La_Obezita2";
            this.La_Obezita2.Size = new System.Drawing.Size(242, 29);
            this.La_Obezita2.TabIndex = 15;
            this.La_Obezita2.Text = "35–40 obezita druhého stupně";
            // 
            // La_Obezita1
            // 
            this.La_Obezita1.BackColor = System.Drawing.Color.Transparent;
            this.La_Obezita1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.La_Obezita1.Location = new System.Drawing.Point(20, 306);
            this.La_Obezita1.Name = "La_Obezita1";
            this.La_Obezita1.Size = new System.Drawing.Size(242, 29);
            this.La_Obezita1.TabIndex = 14;
            this.La_Obezita1.Text = "30–35 obezita prvního stupně";
            // 
            // La_Obezita3
            // 
            this.La_Obezita3.BackColor = System.Drawing.Color.Transparent;
            this.La_Obezita3.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F);
            this.La_Obezita3.Location = new System.Drawing.Point(20, 364);
            this.La_Obezita3.Name = "La_Obezita3";
            this.La_Obezita3.Size = new System.Drawing.Size(242, 29);
            this.La_Obezita3.TabIndex = 16;
            this.La_Obezita3.Text = "> 40 obezita třetího stupně";
            // 
            // Pa_Content
            // 
            this.Pa_Content.BackColor = System.Drawing.Color.Transparent;
            this.Pa_Content.Controls.Add(this.La_Title);
            this.Pa_Content.Controls.Add(this.La_Obezita3);
            this.Pa_Content.Controls.Add(this.NUD_Height);
            this.Pa_Content.Controls.Add(this.La_Obezita2);
            this.Pa_Content.Controls.Add(this.PB_Height);
            this.Pa_Content.Controls.Add(this.La_Obezita1);
            this.Pa_Content.Controls.Add(this.La_HeightTitle);
            this.Pa_Content.Controls.Add(this.La_Nadvaha);
            this.Pa_Content.Controls.Add(this.NUD_Weight);
            this.Pa_Content.Controls.Add(this.La_IdealniVaha);
            this.Pa_Content.Controls.Add(this.PB_Weight);
            this.Pa_Content.Controls.Add(this.La_Podvaha);
            this.Pa_Content.Controls.Add(this.La_WeightTitle);
            this.Pa_Content.Controls.Add(this.La_TezkaPodvyziva);
            this.Pa_Content.Controls.Add(this.La_Result);
            this.Pa_Content.Location = new System.Drawing.Point(0, 0);
            this.Pa_Content.Name = "Pa_Content";
            this.Pa_Content.Size = new System.Drawing.Size(275, 412);
            this.Pa_Content.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(274, 411);
            this.Controls.Add(this.Pa_Content);
            this.MinimumSize = new System.Drawing.Size(290, 450);
            this.Name = "Form1";
            this.Text = "BMI Calculator";
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Height)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.NUD_Weight)).EndInit();
            this.Pa_Content.ResumeLayout(false);
            this.Pa_Content.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.NumericUpDown NUD_Height;
        private System.Windows.Forms.Label La_Title;
        private System.Windows.Forms.ProgressBar PB_Height;
        private System.Windows.Forms.Label La_HeightTitle;
        private System.Windows.Forms.Label La_WeightTitle;
        private System.Windows.Forms.ProgressBar PB_Weight;
        private System.Windows.Forms.NumericUpDown NUD_Weight;
        private System.Windows.Forms.Label La_Result;
        private System.Windows.Forms.Label La_TezkaPodvyziva;
        private System.Windows.Forms.Label La_Podvaha;
        private System.Windows.Forms.Label La_Nadvaha;
        private System.Windows.Forms.Label La_IdealniVaha;
        private System.Windows.Forms.Label La_Obezita2;
        private System.Windows.Forms.Label La_Obezita1;
        private System.Windows.Forms.Label La_Obezita3;
        private System.Windows.Forms.Panel Pa_Content;
    }
}

