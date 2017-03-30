using System;

namespace OOP_DopravniProstredky
{
    public abstract class DopravniProstredek
    {
        public string Nazev { get; set; }
        public Guid Id { get; set; }
        public float HmotnostKg { get; set; }
        public float HmotnostLb
        {
            get
            {
                return HmotnostKg * 2.20462262185f;
            }
        }
        public float RychlostKmH { get; set; }
        public virtual float RychlostMile
        {
            get
            {
                return RychlostKmH * 1.609f;
            }
        }
    }
}
