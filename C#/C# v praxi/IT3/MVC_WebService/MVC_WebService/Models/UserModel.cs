using System;

namespace MVC_WebService.Models
{
    public class UserModel
    {
        public string Email { get; }
        public DateTime LastLogin { get; }

        public UserModel(string email, DateTime lastLogin)
        {
            Email       = email;
            LastLogin   = lastLogin;
        }
    }
}