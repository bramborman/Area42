using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using WebAppMVC_eshop.Models;

namespace WebAppMVC_eshop.Controllers
{
    public class ProdejController : Controller
    {
        // GET: Prodej
        public ActionResult Index()
        {
            return RedirectToAction("Seznam");
        }

        public ActionResult Seznam()
        {
            return View(MainData.DatabazeZbozi);
        }

        public ActionResult Add(Guid id)
        {
            ZboziModel zboziKEditaci = MainData.DatabazeZbozi.Where(d => d.ID == id).FirstOrDefault();

            KosikModel kosik = (KosikModel)Session[Const.SESSION_KOSIK];

            if (kosik == null)
            {
                kosik = new KosikModel();
            }

            int pocetKusu;

            if (kosik.PolozkyVKosiku.TryGetValue(id, out pocetKusu))
            {
                kosik.PolozkyVKosiku[id] = ++pocetKusu;
            }
            else
            {
                kosik.PolozkyVKosiku.Add(id, 1);
            }

            Session[Const.SESSION_KOSIK] = kosik;

            return RedirectToAction("Seznam");
        }

        public ActionResult Remove(Guid id)
        {
            return View(MainData.DatabazeZbozi);
        }
    }
}