namespace WindowsFormsApplication8
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.Bt_DrawHouse = new System.Windows.Forms.Button();
            this.Bt_Clear = new System.Windows.Forms.Button();
            this.Bt_Draw = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)));
            this.pictureBox1.Location = new System.Drawing.Point(13, 13);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(259, 208);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // Bt_DrawHouse
            // 
            this.Bt_DrawHouse.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Bt_DrawHouse.Location = new System.Drawing.Point(116, 226);
            this.Bt_DrawHouse.Name = "Bt_DrawHouse";
            this.Bt_DrawHouse.Size = new System.Drawing.Size(75, 23);
            this.Bt_DrawHouse.TabIndex = 1;
            this.Bt_DrawHouse.Text = "House";
            this.Bt_DrawHouse.UseVisualStyleBackColor = true;
            this.Bt_DrawHouse.Click += new System.EventHandler(this.DrawHouse);
            // 
            // Bt_Clear
            // 
            this.Bt_Clear.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Bt_Clear.Location = new System.Drawing.Point(197, 226);
            this.Bt_Clear.Name = "Bt_Clear";
            this.Bt_Clear.Size = new System.Drawing.Size(75, 23);
            this.Bt_Clear.TabIndex = 2;
            this.Bt_Clear.Text = "Clear";
            this.Bt_Clear.UseVisualStyleBackColor = true;
            this.Bt_Clear.Click += new System.EventHandler(this.Clear);
            // 
            // Bt_Draw
            // 
            this.Bt_Draw.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.Bt_Draw.Location = new System.Drawing.Point(35, 226);
            this.Bt_Draw.Name = "Bt_Draw";
            this.Bt_Draw.Size = new System.Drawing.Size(75, 23);
            this.Bt_Draw.TabIndex = 3;
            this.Bt_Draw.Text = "Draw";
            this.Bt_Draw.UseVisualStyleBackColor = true;
            this.Bt_Draw.Click += new System.EventHandler(this.Draw);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.Bt_Draw);
            this.Controls.Add(this.Bt_Clear);
            this.Controls.Add(this.Bt_DrawHouse);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button Bt_DrawHouse;
        private System.Windows.Forms.Button Bt_Clear;
        private System.Windows.Forms.Button Bt_Draw;
    }
}

