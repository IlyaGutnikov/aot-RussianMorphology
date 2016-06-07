using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AOTLemmatizer;

namespace TestLemmatizerCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            AOTLemmatizer.AOTLemmatizer aotLem = new AOTLemmatizer.AOTLemmatizer();
            string norm = aotLem.Stem("мыла");

            Console.WriteLine(norm);
            List<string> forms = aotLem.GetAllForms("зуд").ToList();
            Console.WriteLine(forms.Count());
            for (int k = 0; k < forms.Count; k++) {

                Console.WriteLine(forms[k].ToString());

            }
            Console.WriteLine("hello world");
            Console.ReadLine();

        }
    }
}
