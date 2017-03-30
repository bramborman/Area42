namespace OOP_DopravniProstredky
{
    public class Kamion : DopravniProstredek, ISilnicniVozidlo
    {
        public float Vyska { get; set; }
        public int ObjemZavazadlovehoProstoru { get; set; }
        public int PocetNaprav { get; set; }
        public bool MaMotor { get; set; }
        public float SpotrebaNa100Km { get; set; }

        public Kamion()
        {
            MaMotor = true;
        }

        public bool Projede(float minVyskaMostu)
        {
            return minVyskaMostu < Vyska;
        }
    }
}
