namespace WindowsFormsApplication3
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
            this.RB_Red = new System.Windows.Forms.RadioButton();
            this.RB_Yellow = new System.Windows.Forms.RadioButton();
            this.RB_Green = new System.Windows.Forms.RadioButton();
            this.RB_Blue = new System.Windows.Forms.RadioButton();
            this.RB_Gray = new System.Windows.Forms.RadioButton();
            this.RB_Pink = new System.Windows.Forms.RadioButton();
            this.SuspendLayout();
            // 
            // RB_Red
            // 
            this.RB_Red.AutoSize = true;
            this.RB_Red.Location = new System.Drawing.Point(13, 14);
            this.RB_Red.Name = "RB_Red";
            this.RB_Red.Size = new System.Drawing.Size(65, 17);
            this.RB_Red.TabIndex = 0;
            this.RB_Red.TabStop = true;
            this.RB_Red.Text = "Červená";
            this.RB_Red.UseVisualStyleBackColor = true;
            this.RB_Red.CheckedChanged += new System.EventHandler(this.ChangeBackgroundColor);
            // 
            // RB_Yellow
            // 
            this.RB_Yellow.AutoSize = true;
            this.RB_Yellow.Location = new System.Drawing.Point(13, 83);
            this.RB_Yellow.Name = "RB_Yellow";
            this.RB_Yellow.Size = new System.Drawing.Size(49, 17);
            this.RB_Yellow.TabIndex = 1;
            this.RB_Yellow.TabStop = true;
            this.RB_Yellow.Text = "Žlutá";
            this.RB_Yellow.UseVisualStyleBackColor = true;
            this.RB_Yellow.CheckedChanged += new System.EventHandler(this.ChangeBackgroundColor);
            // 
            // RB_Green
            // 
            this.RB_Green.AutoSize = true;
            this.RB_Green.Location = new System.Drawing.Point(13, 37);
            this.RB_Green.Name = "RB_Green";
            this.RB_Green.Size = new System.Drawing.Size(58, 17);
            this.RB_Green.TabIndex = 2;
            this.RB_Green.TabStop = true;
            this.RB_Green.Text = "Zelená";
            this.RB_Green.UseVisualStyleBackColor = true;
            this.RB_Green.CheckedChanged += new System.EventHandler(this.ChangeBackgroundColor);
            // 
            // RB_Blue
            // 
            this.RB_Blue.AutoSize = true;
            this.RB_Blue.Location = new System.Drawing.Point(13, 60);
            this.RB_Blue.Name = "RB_Blue";
            this.RB_Blue.Size = new System.Drawing.Size(55, 17);
            this.RB_Blue.TabIndex = 3;
            this.RB_Blue.TabStop = true;
            this.RB_Blue.Text = "Modrá";
            this.RB_Blue.UseVisualStyleBackColor = true;
            this.RB_Blue.CheckedChanged += new System.EventHandler(this.ChangeBackgroundColor);
            // 
            // RB_Gray
            // 
            this.RB_Gray.AutoSize = true;
            this.RB_Gray.Location = new System.Drawing.Point(13, 106);
            this.RB_Gray.Name = "RB_Gray";
            this.RB_Gray.Size = new System.Drawing.Size(50, 17);
            this.RB_Gray.TabIndex = 5;
            this.RB_Gray.TabStop = true;
            this.RB_Gray.Text = "Šedá";
            this.RB_Gray.UseVisualStyleBackColor = true;
            this.RB_Gray.CheckedChanged += new System.EventHandler(this.ChangeBackgroundColor);
            // 
            // RB_Pink
            // 
            this.RB_Pink.AutoSize = true;
            this.RB_Pink.Location = new System.Drawing.Point(13, 129);
            this.RB_Pink.Name = "RB_Pink";
            this.RB_Pink.Size = new System.Drawing.Size(62, 17);
            this.RB_Pink.TabIndex = 6;
            this.RB_Pink.TabStop = true;
            this.RB_Pink.Text = "Růžová";
            this.RB_Pink.UseVisualStyleBackColor = true;
            this.RB_Pink.CheckedChanged += new System.EventHandler(this.ChangeBackgroundColor);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.RB_Pink);
            this.Controls.Add(this.RB_Gray);
            this.Controls.Add(this.RB_Blue);
            this.Controls.Add(this.RB_Green);
            this.Controls.Add(this.RB_Yellow);
            this.Controls.Add(this.RB_Red);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton RB_Red;
        private System.Windows.Forms.RadioButton RB_Yellow;
        private System.Windows.Forms.RadioButton RB_Green;
        private System.Windows.Forms.RadioButton RB_Blue;
        private System.Windows.Forms.RadioButton RB_Gray;
        private System.Windows.Forms.RadioButton RB_Pink;
    }
}

