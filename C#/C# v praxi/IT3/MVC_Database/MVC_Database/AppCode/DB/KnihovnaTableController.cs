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
                var a = output.First().SkolaZaci;

                return output;
            }
        }
    }
}