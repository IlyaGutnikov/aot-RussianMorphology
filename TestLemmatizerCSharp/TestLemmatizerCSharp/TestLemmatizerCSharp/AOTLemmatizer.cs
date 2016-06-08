using System.Collections.Generic;
using System.Linq;
using LEMMATIZERLib;

/// <summary>
/// AOTLemmatizer
/// </summary>
namespace AOTLemmatizer
{
    /// <summary>
    /// Класс взаимодействия с AOT
    /// </summary>
    class AOTLemmatizer
    {
        private readonly ILemmatizer lemmatizerRu;
        /// <summary>
        /// this needs 32 bit version of project
        /// You can change it in project properties
        /// </summary>
        public AOTLemmatizer()
        {
            lemmatizerRu = new LemmatizerRussian();
            lemmatizerRu.LoadDictionariesRegistry();
        }

        /// <summary>
        /// Получили первую норму которая подходит для слова
        /// </summary>
        /// <param name="word">Входное слово для которого находим норму</param>
        /// <returns>Норма слова</returns>
        public string Stem(string word)
        {
            return GetAllNorms(word).First();
        }

        /// <summary>
        /// Получить все нормы слова
        /// </summary>
        /// <param name="word">Входное слово</param>
        /// <returns>Все нормы слова</returns>
        public IEnumerable<string> GetAllNorms(string word)
        {
            IParadigmCollection piParadigmCollection = lemmatizerRu.CreateParadigmCollectionFromForm(word, 0, 0);
            var len = piParadigmCollection.Count;
            for (int i = 0; i < len; ++i)
                yield return piParadigmCollection[i].Norm.ToLower();
        }

        /// <summary>
        /// Получить все формы слова
        /// </summary>
        /// <param name="word">Входное слово</param>
        /// <returns>Все формы слова</returns>
        public IEnumerable<string> GetAllForms(string word)
        {
            IParadigmCollection piParadigmCollection = lemmatizerRu.CreateParadigmCollectionFromNorm(word, 0, 0);

            for (int i = 0; i < piParadigmCollection.Count; ++i)
            {
                for (uint j = 0; j < piParadigmCollection[i].Count; j++)
                {
                    yield return piParadigmCollection[i][j].ToLower();
                }
            }
        }
    }
}
