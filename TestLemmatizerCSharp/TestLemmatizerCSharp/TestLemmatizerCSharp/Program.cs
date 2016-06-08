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
        public static string inputWord = "";
        public static string inputCommand = "";
        public static bool check = false;

        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                inputCommand = args[0];
                if (args.Length > 1)
                {
                    inputWord = args[1];
                    check = true;
                }
            }

            else {

                Console.WriteLine("error");
                check = false;
            }
            if (check == true)
            {
                //создали лемматайзер
                AOTLemmatizer.AOTLemmatizer aotLem = new AOTLemmatizer.AOTLemmatizer();

                if ((!inputCommand.Equals("GetAllNorms")) && (!inputCommand.Equals("GetAllForms")) && (!inputCommand.Equals("Stem")))
                {
                    Console.WriteLine("error");
                }

                if (inputCommand.Equals("GetAllForms"))
                {
                    List<string> forms = aotLem.GetAllForms(inputWord).ToList();
                    for (int k = 0; k < forms.Count; k++)
                    {
                        Console.WriteLine(forms[k].ToString());
                    }
                }

                if (inputCommand.Equals("GetAllNorms"))
                {
                    List<string> norms = aotLem.GetAllNorms(inputWord).ToList();
                    for (int k = 0; k < norms.Count; k++)
                    {
                        Console.WriteLine(norms[k].ToString());
                    }
                }

                if (inputCommand.Equals("Stem"))
                {
                    string stem = aotLem.Stem(inputWord);
                    Console.WriteLine(stem);
                }
            }
            //Console.ReadLine();

        }
    }
}
