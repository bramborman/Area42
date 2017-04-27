using System.Collections.Generic;
using System.Linq;

namespace MVC_Database.AppCode.DB
{
    public sealed class InfoOZapujceniTableController
    {
        public List<InfoOZapujceni> GetInfoOZapujceni()
        {
            using (DatabaseSchoolEntities db = new DatabaseSchoolEntities())
            {
                List<InfoOZapujceni> output = db.InfoOZapujceni.ToList();

                foreach (InfoOZapujceni info in output)
                {
                    var a = info.Knihovna;
                    var b = info.SkolaZaci;
                }

                return output;
            }
        }
    }
}