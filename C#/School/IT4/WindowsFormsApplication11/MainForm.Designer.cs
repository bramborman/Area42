namespace WindowsFormsApplication11
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
            this.redInput = new System.Windows.Forms.NumericUpDown();
            this.greenInput = new System.Windows.Forms.NumericUpDown();
            this.blueInput = new System.Windows.Forms.NumericUpDown();
            this.timeLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.redInput)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.greenInput)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.blueInput)).BeginInit();
            this.SuspendLayout();
            // 
            // redInput
            // 
            this.redInput.Location = new System.Drawing.Point(83, 87);
            this.redInput.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.redInput.Name = "redInput";
            this.redInput.Size = new System.Drawing.Size(120, 20);
            this.redInput.TabIndex = 0;
            this.redInput.Value = new decimal(new int[] {
            17,
            0,
            0,
            0});
            this.redInput.ValueChanged += new System.EventHandler(this.ColorChanged);
            // 
            // greenInput
            // 
            this.greenInput.Location = new System.Drawing.Point(83, 114);
            this.greenInput.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.greenInput.Name = "greenInput";
            this.greenInput.Size = new System.Drawing.Size(120, 20);
            this.greenInput.TabIndex = 1;
            this.greenInput.Value = new decimal(new int[] {
            107,
            0,
            0,
            0});
            this.greenInput.ValueChanged += new System.EventHandler(this.ColorChanged);
            // 
            // blueInput
            // 
            this.blueInput.Location = new System.Drawing.Point(83, 141);
            this.blueInput.Maximum = new decimal(new int[] {
            255,
            0,
            0,
            0});
            this.blueInput.Name = "blueInput";
            this.blueInput.Size = new System.Drawing.Size(120, 20);
            this.blueInput.TabIndex = 2;
            this.blueInput.Value = new decimal(new int[] {
            179,
            0,
            0,
            0});
            this.blueInput.ValueChanged += new System.EventHandler(this.ColorChanged);
            // 
            // timeLabel
            // 
            this.timeLabel.BackColor = System.Drawing.Color.Black;
            this.timeLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.timeLabel.ForeColor = System.Drawing.Color.White;
            this.timeLabel.Location = new System.Drawing.Point(80, 175);
            this.timeLabel.Name = "timeLabel";
            this.timeLabel.Size = new System.Drawing.Size(123, 23);
            this.timeLabel.TabIndex = 3;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.timeLabel);
            this.Controls.Add(this.blueInput);
            this.Controls.Add(this.greenInput);
            this.Controls.Add(this.redInput);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "MainForm";
            this.Text = "Colors";
            ((System.ComponentModel.ISupportInitialize)(this.redInput)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.greenInput)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.blueInput)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.NumericUpDown redInput;
        private System.Windows.Forms.NumericUpDown greenInput;
        private System.Windows.Forms.NumericUpDown blueInput;
        private System.Windows.Forms.Label timeLabel;
    }
}

