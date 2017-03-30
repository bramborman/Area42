namespace OOP_DopravniProstredky
{
    public interface ISilnicniVozidlo : IMotoroveVozidlo
    {
        float Vyska { get; set; }
        int ObjemZavazadlovehoProstoru { get; set; }

        bool Projede(float minVyskaMostu);
    }
}
