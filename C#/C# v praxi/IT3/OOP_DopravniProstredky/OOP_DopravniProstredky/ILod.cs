namespace OOP_DopravniProstredky
{
    public interface ILod
    {
        float Vytlak { get; set; }
        float Ponor { get; set; }

        bool Propluje(int minHloubkaReky);
    }
}
