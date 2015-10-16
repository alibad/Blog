using System;
using System.Text;

namespace SPIcon
{
    public enum MessageType
    {
        None,
        Info,
        Error
    }

    /// <summary>
    /// Represents a message to be communicated with the user
    /// </summary>
    public struct MessagePack
    {
        private string message;
        private string details;
        private MessageType type;
        private Exception exception;
        private bool isFull;

        #region Properties

        /// <summary>
        /// The direct message to be communicated to the user.
        /// </summary>
        public string Message
        {
            get
            {
                return message;
            }
            set
            {
                message = value;

                if (message != null)
                {
                    isFull = true;
                    type = MessageType.Info;
                    exception = null;
                    details = null;
                }
            }
        }

        /// <summary>
        /// Any extra details to be communicated about the message.
        /// </summary>
        public string Details
        {
            get
            {
                return details;
            }
            set
            {
                details = value;
            }
        }

        /// <summary>
        /// The type of the message
        /// </summary>
        public MessageType Type
        {
            get
            {
                return type;
            }
            set
            {
                type = value;

                if (type != MessageType.Error)
                {
                    exception = null;
                }
            }
        }

        /// <summary>
        /// The exception in case the message communicated is a result of an exception
        /// </summary>
        public Exception Exception
        {
            get
            {
                return exception;
            }
            set
            {
                exception = value;

                if (exception != null && details == null)
                {
                    isFull = true;

                    //  Populate message details
                    StringBuilder sb = new StringBuilder();

                    sb.AppendFormat("Source\t\t {0}\n", exception.Source);
                    sb.AppendFormat("Error\t\t {0}\n", Utils.Wrap(exception.Message, "\n\t\t", 50));
                    //sb.AppendFormat("Stack Trace\t\t {0}\n", Utils.Wrap(exception.StackTrace, "\n\t\t", 50));

                    if (exception.InnerException != null)
                    {
                        sb.AppendFormat("Original Source\t {0}\n", exception.InnerException.Source);
                        sb.AppendFormat("Original Error\t {0}\n", Utils.Wrap(exception.InnerException.Message, "\n\t\t", 50));
                        //sb.AppendFormat("Original Stack Trace\t\t {0}\n", Utils.Wrap(exception.InnerException.StackTrace, "\n\t\t", 50));
                    }

                    details = sb.ToString();

                    //  Change the message type
                    type = MessageType.Error;
                }
            }
        }

        /// <summary>
        /// Whether the message is empty or not.
        /// </summary>
        public bool IsEmpty
        {
            get
            {
                return !isFull;
            }
            set
            {
                isFull = !value;

                if (!isFull)
                {
                    message = null;
                    details = null;
                    exception = null;
                    type = MessageType.None;
                }
            }
        }

        #endregion
    }
}
