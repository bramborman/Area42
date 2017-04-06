using System.Collections.Generic;
using System.Linq;

namespace MVC_Database.AppCode.DB
{
    public class DatabaseSchoolController
    {
        public List<SkolaZaci> GetAll()
        {
            List<SkolaZaci> output;

            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                output = db.SkolaZacis.ToList();
            }

            return output;
        }

        public List<SkolaZaci> GetZaciByPrijmeni(string prijmeni)
        {
            List<SkolaZaci> output;

            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                output = db.SkolaZacis.Where(z => z.Prijmeni == prijmeni).ToList();
            }

            return output;
        }

        public SkolaZaci GetZakById(int id)
        {
            SkolaZaci output;

            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                output = db.SkolaZacis.FirstOrDefault(z => z.Id == id);
            }

            return output;
        }
    }
}