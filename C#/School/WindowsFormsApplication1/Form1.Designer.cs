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
            this.La_HelloWorld = new System.Windows.Forms.Label();
            this.Bt_ToggleHelloWorld = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // La_HelloWorld
            // 
            this.La_HelloWorld.AutoSize = true;
            this.La_HelloWorld.Font = new System.Drawing.Font("Microsoft Sans Serif", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.La_HelloWorld.Location = new System.Drawing.Point(0, 0);
            this.La_HelloWorld.Margin = new System.Windows.Forms.Padding(0);
            this.La_HelloWorld.Name = "La_HelloWorld";
            this.La_HelloWorld.Size = new System.Drawing.Size(196, 39);
            this.La_HelloWorld.TabIndex = 0;
            this.La_HelloWorld.Text = "Hello world!";
            this.La_HelloWorld.Visible = false;
            // 
            // Bt_ToggleHelloWorld
            // 
            this.Bt_ToggleHelloWorld.AutoSize = true;
            this.Bt_ToggleHelloWorld.Location = new System.Drawing.Point(0, 0);
            this.Bt_ToggleHelloWorld.Name = "Bt_ToggleHelloWorld";
            this.Bt_ToggleHelloWorld.Size = new System.Drawing.Size(81, 23);
            this.Bt_ToggleHelloWorld.TabIndex = 1;
            this.Bt_ToggleHelloWorld.Text = "Toggle World";
            this.Bt_ToggleHelloWorld.UseVisualStyleBackColor = true;
            this.Bt_ToggleHelloWorld.Click += new System.EventHandler(this.Bt_ToggleHelloWorld_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.Bt_ToggleHelloWorld);
            this.Controls.Add(this.La_HelloWorld);
            this.Name = "Form1";
            this.Text = "Hello world";
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label La_HelloWorld;
        private System.Windows.Forms.Button Bt_ToggleHelloWorld;
    }
}

