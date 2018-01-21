namespace WindowsFormsApplication12
{
    partial class CardControl
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.foregroundLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // foregroundLabel
            // 
            this.foregroundLabel.Location = new System.Drawing.Point(0, 0);
            this.foregroundLabel.Margin = new System.Windows.Forms.Padding(0);
            this.foregroundLabel.Name = "foregroundLabel";
            this.foregroundLabel.Size = new System.Drawing.Size(150, 150);
            this.foregroundLabel.TabIndex = 0;
            this.foregroundLabel.Click += new System.EventHandler(this.OnClick);
            // 
            // CardControl
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Highlight;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.Controls.Add(this.foregroundLabel);
            this.Name = "CardControl";
            this.Click += new System.EventHandler(this.OnClick);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label foregroundLabel;
    }
}
