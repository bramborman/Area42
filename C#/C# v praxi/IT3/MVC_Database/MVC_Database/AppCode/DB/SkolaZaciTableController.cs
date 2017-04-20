using System.Collections.Generic;
using System.Linq;

namespace MVC_Database.AppCode.DB
{
    public sealed class SkolaZaciTableController
    {
        public List<SkolaZaci> GetAll()
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                return db.SkolaZacis.ToList();
            }
        }

        public List<SkolaZaci> GetZaciWithPrijmeni(string prijmeni)
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                return db.SkolaZacis.Where(z => z.Prijmeni == prijmeni).ToList();
            }
        }

        public SkolaZaci GetZakById(int id)
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                return db.SkolaZacis.FirstOrDefault(z => z.Id == id);
            }
        }

        public void AddZak(SkolaZaci zak)
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                db.SkolaZacis.Add(zak);
                db.SaveChanges();
            }
        }

        public void DeleteZak(int id)
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                db.SkolaZacis.Remove(db.SkolaZacis.First(s => s.Id == id));
                db.SaveChanges();
            }
        }
    }
}