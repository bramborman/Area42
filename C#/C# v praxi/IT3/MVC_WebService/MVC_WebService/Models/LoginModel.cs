using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace MVC_WebService.Models
{
    public class LoginModel
    {
        [DisplayName("EMAIL")]
        [DataType(DataType.EmailAddress)]
        public string Email { get; set; }
        [DisplayName("HESLO")]
        [DataType(DataType.Password)]
        public string Password { get; set; }
        public string Url { get; set; }
    }
}