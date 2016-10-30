using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Web;
using System.Web.Mvc;
using WebAppMVC_2.Models;

namespace WebAppMVC_2.Controllers
{
    public class GalleryController : Controller
    {
        // GET: Gallery
        public ActionResult Index()
        {
            return (RedirectToAction("ShowGallery"));
        }

        public ActionResult ShowGallery()
        {
            List<ImageModel> images = new List<ImageModel>();

            string[] files = Directory.GetFiles(HttpRuntime.AppDomainAppPath + "img\\");

            int i = 0;

            foreach (var item in files)
            {
                ImageModel image = new ImageModel();

                image.ID = ++i;
                image.FileName = item.Substring(item.LastIndexOf('\\') + 1);
                image.FileLocationDisc = item;
                image.FileLocationWeb = "../img/" + image.FileName;

                images.Add(image);
            }

            return View(images);
        }

        public ActionResult ShowImage(int id)
        {
            ImageModel image = new ImageModel();

            image.ID = id;
            image.FileName = string.Format("file{0}.jpg", id);
            image.FileLocationWeb = "/img/" + image.FileName;

            return View(image);
        }
    }
}