namespace Videostop
{
    partial class MainForm
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
            this.PictureBox = new System.Windows.Forms.PictureBox();
            this.StartStopButton = new System.Windows.Forms.Button();
            this.PointsLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // PictureBox
            // 
            this.PictureBox.Location = new System.Drawing.Point(12, 60);
            this.PictureBox.Name = "PictureBox";
            this.PictureBox.Size = new System.Drawing.Size(276, 126);
            this.PictureBox.TabIndex = 0;
            this.PictureBox.TabStop = false;
            // 
            // StartStopButton
            // 
            this.StartStopButton.FlatAppearance.BorderColor = System.Drawing.Color.Black;
            this.StartStopButton.FlatAppearance.BorderSize = 2;
            this.StartStopButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Silver;
            this.StartStopButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Gainsboro;
            this.StartStopButton.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.StartStopButton.Font = new System.Drawing.Font("Segoe UI Semibold", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.StartStopButton.Location = new System.Drawing.Point(12, 192);
            this.StartStopButton.Name = "StartStopButton";
            this.StartStopButton.Size = new System.Drawing.Size(276, 57);
            this.StartStopButton.TabIndex = 1;
            this.StartStopButton.Text = "START";
            this.StartStopButton.UseVisualStyleBackColor = true;
            this.StartStopButton.Click += new System.EventHandler(this.StartStopButton_Click);
            // 
            // PointsLabel
            // 
            this.PointsLabel.BackColor = System.Drawing.Color.Transparent;
            this.PointsLabel.Font = new System.Drawing.Font("Segoe UI Black", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PointsLabel.Location = new System.Drawing.Point(13, 13);
            this.PointsLabel.Name = "PointsLabel";
            this.PointsLabel.Size = new System.Drawing.Size(274, 44);
            this.PointsLabel.TabIndex = 2;
            this.PointsLabel.Text = "ʢ◉ᴥ◉ʡ";
            this.PointsLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(299, 261);
            this.Controls.Add(this.PointsLabel);
            this.Controls.Add(this.StartStopButton);
            this.Controls.Add(this.PictureBox);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.ShowIcon = false;
            this.Text = "Videostop";
            ((System.ComponentModel.ISupportInitialize)(this.PictureBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox PictureBox;
        private System.Windows.Forms.Button StartStopButton;
        private System.Windows.Forms.Label PointsLabel;
    }
}

