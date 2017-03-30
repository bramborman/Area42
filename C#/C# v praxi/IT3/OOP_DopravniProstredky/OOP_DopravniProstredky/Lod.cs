namespace OOP_DopravniProstredky
{
    public class Lod : DopravniProstredek, ILod, IMotoroveVozidlo
    {
        public float Vytlak { get; set; }
        public float Ponor { get; set; }
        public bool MaMotor { get; set; }
        public float SpotrebaNa100Km { get; set; }
        public override float RychlostMile
        {
            get
            {
                return RychlostKmH * 1.852f;
            }
        }

        public bool Propluje(int minHloubkaReky)
        {
            return Ponor < minHloubkaReky;
        }
    }
}
