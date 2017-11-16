using System;
using System.Linq;                                                                      
                                                                                        
namespace ConsoleApplication33                                                          
{                                                                                       
    public static class Program                                                         
    {                                                                                   
        public static void Main(string[] args)                                          
        {
            int min = SetRandomValues(new int[10]);                                     
                                                                                        
            Console.WriteLine();                                                        
            Console.Write($"Nejmensi cislo: {min}");                                    
                                                                                        
            Console.ReadKey();                                                          
        }                                                                               
                                                                                        
        private static int SetRandomValues(int[] array)                                 
        {                                                                               
            Random random = new Random();                                               
                                                                                        
            for (int i = 0; i < array.Length; i++)                                      
            {                                                                           
                array[i] = random.Next(100);                                            
                Console.Write($"{array[i]}, ");                                         
            }                                                                           
                                                                                        
            Console.Write("\b\b ");                                                     
            return array.Min();                                                         
        }                                                                               
    }                                                                                   
}                                                                                       
                                                                                        