using System.ComponentModel;
using System.ComponentModel.DataAnnotations;

namespace MVC_WebService.Models
{
    public class LoginModel
    {
        [DisplayName("EMAIL")]
        [DataType(DataType.EmailAddress)]
        [StringLength(100, MinimumLength = 5)]
        [Required]
        public string Email { get; set; }

        [DisplayName("HESLO")]
        [DataType(DataType.Password)]
        [StringLength(100, MinimumLength = 3)]
        [Required]
        public string Password { get; set; }
        public string Url { get; set; }
    }
}