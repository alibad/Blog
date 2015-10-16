using System.Xml.Serialization;
using System.Collections.Generic;

namespace LibrarySchema
{

    [XmlType(Namespace = "http://schemas.ali.com/lib/")]
    [XmlRoot("Library", Namespace = "http://schemas.ali.com/lib/", IsNullable = false)]
    public partial class LibraryType
    {
        private List<BookType> booksField;
        private List<EmployeeType> employeesField;

        [XmlArrayItem("Book", IsNullable = false)]
        public List<BookType> Books
        {
            get
            {
                return this.booksField;
            }
            set
            {
                this.booksField = value;
            }
        }

        [XmlArrayItem("Employee", IsNullable = false)]
        public List<EmployeeType> Employees
        {
            get
            {
                return this.employeesField;
            }
            set
            {
                this.employeesField = value;
            }
        }
    }

    [XmlType(Namespace = "http://schemas.ali.com/lib/")]
    public partial class BookType
    {
        private string titleField;
        private string authorField;

        [XmlAttribute()]
        public string Title
        {
            get
            {
                return this.titleField;
            }
            set
            {
                this.titleField = value;
            }
        }

        [XmlAttribute()]
        public string Author
        {
            get
            {
                return this.authorField;
            }
            set
            {
                this.authorField = value;
            }
        }
    }

    [XmlType(Namespace = "http://schemas.ali.com/lib/")]
    public partial class EmployeeType
    {
        private string nameField;

        [XmlAttribute()]
        public string Name
        {
            get
            {
                return this.nameField;
            }
            set
            {
                this.nameField = value;
            }
        }
    }
}