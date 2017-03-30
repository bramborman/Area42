namespace OOP_DopravniProstredky
{
    public class OsobniAuto : DopravniProstredek, ISilnicniVozidlo
    {
        public float Vyska { get; set; }
        public int ObjemZavazadlovehoProstoru { get; set; }
        public int MaxPocetOsob { get; set; }
        public bool MaMotor { get; set; }
        public float SpotrebaNa100Km { get; set; }

        public bool Projede(float minVyskaMostu)
        {
            return minVyskaMostu < Vyska;
        }
    }
}
