using System;
using System.Collections.Generic;
using System.Xml;
using System.Text;
using System.Xml.Serialization;
using System.IO;
using System.Collections;
using System.Reflection;
using LibrarySchema;

namespace LibSerializer
{
    class Program
    {
        static void Main(string[] args)
        {
            #region 1
            //LibraryType library = new LibraryType();
            //library.Books = new BooksType();
            //library.Books.Book = new List<BookType>();
            //BookType newBook = new BookType();
            //newBook.Title = "Book 1";
            //newBook.Author = "Author 1";
            //library.Books.Book.Add(newBook);
            #endregion

            #region 2
            //LibraryType library = new LibraryType();
            //library.Books = new List<BookType>();
            //BookType newBook = new BookType();
            //newBook.Title = "Book 1";
            //newBook.Author = "Author 1";
            //library.Books.Add(newBook);
            #endregion

            #region 3
            ////  Create a library 
            //LibraryType library = new LibraryType();

            ////  Create Books tag
            //library.Books = new List<BookType>();

            ////  Add 5 books to the library
            //for (int i = 1; i <= 5; i++)
            //{
            //    BookType book = new BookType();
            //    book.Title = string.Format("Book {0}", i);
            //    book.Author = string.Format("Author {0}", i);
            //    library.Books.Add(book);
            //}

            ////  Create employees tag
            //library.Employees = new List<EmployeeType>();

            ////  Add 3 employees to the library
            //for (int i = 1; i <= 3; i++)
            //{
            //    EmployeeType employee = new EmployeeType();
            //    employee.Name = string.Format("Book {0}", i);
            //    library.Employees.Add(employee);
            //}

            //////  Now that the object is created, serialize it and print out resulting Xml
            ////XmlSerializer serializer = new XmlSerializer(typeof(LibraryType));
            ////StringWriter sw = new StringWriter();
            ////serializer.Serialize(sw, library);
            ////Console.WriteLine("Object serialized to Xml:\n\n{0}", sw.ToString());
            #endregion

            #region 4
            //  Create our own xml serializer namespace 
            //  Avoiding default xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" 
            //  and xmlns:xsd="http://www.w3.org/2001/XMLSchema" 
            XmlSerializerNamespaces ns = new XmlSerializerNamespaces();

            //  Add lib namespace with empty prefix
            ns.Add("", "http://schemas.ali.com/lib/");

            ////  Now serialize by passing the XmlSerializerNamespaces object 
            ////  as a parameter to the Serialize() method
            //XmlSerializer serializer = new XmlSerializer(typeof(LibraryType));
            //StringWriter sw = new StringWriter();
            //serializer.Serialize(sw, library, ns);
            //Console.WriteLine("Object serialized to Xml:\n\n{0}", sw.ToString());
            #endregion

            #region 5
            ////  Read the first Xml file
            //TextReader tr = new StreamReader(FilePaths.Path1);

            ////  Deserialize the Xml file into a LibraryType object
            //XmlSerializer serializer = new XmlSerializer(typeof(LibraryType));
            //LibraryType lib1 = (LibraryType)serializer.Deserialize(tr);

            //if (lib1.Books == null)
            //{
            //    lib1.Books = new List<BookType>();
            //}

            //BookType newBook = new BookType();
            //newBook.Title = "Book 3";
            //lib1.Books.Add(newBook);

            ////  Serialize back the library type object and output Xml
            //StringWriter sw = new StringWriter();
            //serializer.Serialize(sw, lib1, ns);
            //Console.WriteLine("{0}:\n\n{1}", FilePaths.Path1, sw.ToString());
            #endregion

            #region 6
            //  Read the second Xml file
            TextReader tr = new StreamReader(FilePaths.Path2);

            //  Deserialize the Xml file into a LibraryType object
            XmlSerializer serializer = new XmlSerializer(typeof(LibraryType));
            LibraryType lib2 = (LibraryType)Deserialize(serializer, tr, typeof(LibraryType).Namespace);
            //  Serialize the object to Xml with UTF8 encoding
            string xml = Serialize(serializer, Encoding.Default, ns, true, lib2);
            
            Console.WriteLine("\n{0}:\n\n{1}", FilePaths.Path2, xml);
            #endregion
        }

        /// <summary>
        /// Serializes the object to Xml based on encoding and name spaces.
        /// </summary>
        /// <param name="serializer">XmlSerializer object (passing as param to avoid creating one every time)</param>
        /// <param name="encoding">The encoding of the serialized Xml</param>
        /// <param name="ns">The namespaces to be used by the serializer</param>
        /// <param name="omitDeclaration">Whether to omit Xml declarartion or not</param>
        /// <param name="objectToSerialize">The object we want to serialize to Xml</param>
        /// <returns></returns>
        public static string Serialize(XmlSerializer serializer,
                                       Encoding encoding,
                                       XmlSerializerNamespaces ns,
                                       bool omitDeclaration,
                                       object objectToSerialize)
        {
            MemoryStream ms = new MemoryStream();
            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;
            settings.OmitXmlDeclaration = true;
            settings.Encoding = encoding;
            XmlWriter writer = XmlWriter.Create(ms, settings);
            serializer.Serialize(writer, objectToSerialize, ns);
            return encoding.GetString(ms.ToArray()); ;
        }


        /// <summary>
        /// Deserializes the passed Xml then deallocated any instantiated and empty lists.
        /// </summary>
        /// <param name="serializer"></param>
        /// <param name="tr"></param>
        /// <param name="objectNamespace"></param>
        /// <returns></returns>
        public static object Deserialize(XmlSerializer serializer, TextReader tr, string objectNamespace)
        {
            //  Deserialize Xml into object
            object objectToReturn = serializer.Deserialize(tr);

            //  Clean up empty lists
            CleanUpEmptyLists(objectToReturn, objectNamespace);

            return objectToReturn;
        }

        /// <summary>
        /// Sets any empty lists in the passed object to null. If the passed object itself is a list,
        /// the method returns true of it's empty and false otherwise.
        /// </summary>
        /// <param name="o"></param>
        /// <param name="objectNamespace"></param>
        /// <returns></returns>
        public static bool CleanUpEmptyLists(object o, string objectNamespace)
        {
            //  Skip if the object is already null
            if (o == null)
            {
                return false;
            }

            //  Get the types of the object
            Type type = o.GetType();

            //  If this is an empty list, set it to null
            if (o is IList)
            {
                IList list = (IList)o;

                if (list.Count == 0)
                {
                    return true;
                }
                else
                {
                    foreach (object obj in list)
                    {
                        CleanUpEmptyLists(obj, objectNamespace);
                    }
                }

                return false;
            }
            //  Ignore any objects that aren't in our namespace for perf reasons
            //  and to avoid getting errors on trying to get into every little detail
            else if (type.Namespace != objectNamespace)
            {
                return false;
            }

            //  Loop over all properties and handle them
            foreach (PropertyInfo property in type.GetProperties())
            {
                //  Get the property value and clean up any empty lists it contains
                object propertyValue = property.GetValue(o, null);
                if (CleanUpEmptyLists(propertyValue, objectNamespace))
                {
                    property.SetValue(o, null, null);
                }
            }

            return false;
        }
    }
}
