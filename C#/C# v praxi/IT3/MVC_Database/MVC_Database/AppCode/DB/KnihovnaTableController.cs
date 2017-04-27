using System;
using System.Collections.Generic;
using System.Linq;

namespace MVC_Database.AppCode.DB
{
    public sealed class KnihovnaTableController
    {
        public List<Knihovna> GetAll()
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                return db.Knihovna.ToList();
            }
        }

        public List<Knihovna> GetAllOnZak(int idZaka)
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                List<Knihovna> output = db.Knihovna.Where(k => k.SkolaZaci.Id == idZaka).ToList();

                if (output.Count >= 1)
                {
                    // To make SkolaZaci property available
                    var a = output.First().SkolaZaci;
                }

                return output;
            }
        }

        public List<Knihovna> GetAllNepujcene()
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                return db.Knihovna.Where(i => i.ZapujcenoID == null).ToList();
            }
        }

        public void PujcitKnihuZakovi(int idKnihy, int idZaka)
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                db.Knihovna.Find(idKnihy).ZapujcenoID = idZaka;
                db.InfoOZapujceni.Add(new InfoOZapujceni
                {
                    DatumZapujceni  = DateTime.Now,
                    KnihovnaID      = idKnihy,
                    SkolaZaciID     = idZaka
                });

                db.SaveChanges();
            }
        }

        public void VratitKnihuOdZaka(int idKnihy, int idZaka)
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                db.InfoOZapujceni.First(i => i.KnihovnaID == idKnihy && i.SkolaZaciID == idZaka && i.DatumVraceni == null).DatumVraceni = DateTime.Now;
                db.Knihovna.Find(idKnihy).ZapujcenoID = null;

                db.SaveChanges();
            }
        }
    }
}