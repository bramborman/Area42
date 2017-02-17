using MVC_WebService.Models;
using System;
using System.Web.Mvc;

namespace MVC_WebService.Controllers
{
    public class LoginController : Controller
    {
        [HttpGet]
        public ActionResult Index(string url)
        {
            return View(new LoginModel { Url = url });
        }
        
        [HttpPost]
        public ActionResult Index(LoginModel loginModel)
        {
            bool success = loginModel.Email == "foo@bar.com" && loginModel.Password == "foo";
            ViewBag.BadPassword = !success;

            if (success)
            {
                Session.Add(Constants.SESSION_USER, new UserModel(loginModel.Email, DateTime.Now));

                string[] url = loginModel.Url?.Split('/') ?? new string[2];

                if (url[0] == "Login" || string.IsNullOrWhiteSpace(url[0]))
                {
                    url[0] = Constants.DEFAULT_CONTROLLER;
                    url[1] = Constants.DEFAULT_ACTION;
                }

                return RedirectToAction(url[1], url[0]);
            }
            else
            {
                loginModel.Password = "";
                return View(loginModel);
            }
        }

        public ActionResult Logout(string url)
        {
            Session.Remove(Constants.SESSION_USER);
            return RedirectToAction("Index", new { url = url });
        }
    }
}