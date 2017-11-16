namespace WindowsFormsApplication1
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
            this.textFoo = new System.Windows.Forms.TextBox();
            this.labelBar = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textFoo
            // 
            this.textFoo.Location = new System.Drawing.Point(12, 36);
            this.textFoo.Name = "textFoo";
            this.textFoo.Size = new System.Drawing.Size(260, 20);
            this.textFoo.TabIndex = 0;
            this.textFoo.TextChanged += new System.EventHandler(this.textFoo_TextChanged);
            // 
            // labelBar
            // 
            this.labelBar.AutoSize = true;
            this.labelBar.Location = new System.Drawing.Point(13, 137);
            this.labelBar.Name = "labelBar";
            this.labelBar.Size = new System.Drawing.Size(0, 13);
            this.labelBar.TabIndex = 1;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.labelBar);
            this.Controls.Add(this.textFoo);
            this.Name = "Form1";
            this.Text = "Hello World víc";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textFoo;
        private System.Windows.Forms.Label labelBar;
    }
}

