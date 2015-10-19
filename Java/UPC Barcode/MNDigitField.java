import java.awt.*;
import javax.swing.*;
import javax.swing.text.*;
import javax.swing.event.*;

//***************************************************************************
// This is a class that allows you to create a text field with only digits
// and with a maximum of N digits. Once the number of digits becomes M, an
// MAction is performed on the MComponent. And once the number of digits
// is not M anymore, an MReaction is performed. The same is true for N. Once
// the number of digits becomes N, an NAction is performed on the NComponent. 
//    
// Author: Ali Badereddin
// Date:   September 11, 2005
//
//***************************************************************************
public class MNDigitField extends JTextField
{
	private static final long serialVersionUID = -5976933804176751984L;

	//  Represents the current length of the text in this text field
    private static int currentLength = 0;

    //  The value that causes MActor to act
    private static int M;
    
    //  The maximum number of digits the field can hold
    //  Also, this is the value that triggers the NAction
    private static int N;
    
    //  Represents M Component Actor
    private static ComponentActor MComponentActor;
    
    //  Represents N Component Actor
    private static ComponentActor NComponentActor;
    
    //---------------------------------------------------------------------
    //  Constructor...
    //---------------------------------------------------------------------
    public MNDigitField (int m, int n, JComponent mComp, JComponent nComp,
                        int cols)
    {
        //  Specify the width of the text field in terms of columns
        super (cols);
        
        //  Set M and N
        this.M = m;
        this.N = n;
        
        //  create component actors
        this.MComponentActor = new ComponentActor (mComp);
        this.NComponentActor = new ComponentActor (nComp);

        //  Set the action type to ENABLE (This is default type, but I'm
        //  resetting to emphasize the idea)
        this.MComponentActor.setActionType (ComponentActor.ENABLE);
        this.NComponentActor.setActionType (ComponentActor.ENABLE);
        
        //  Add document listener to the text field
        this.getDocument().addDocumentListener (new MNDocumentListener ());
    }
    
    //---------------------------------------------------------------------
    //  Tells how many digits there are in the text field.
    //---------------------------------------------------------------------
    public int howManyDigits ()
    {
        return this.getText().length ();
    }
    
    //---------------------------------------------------------------------
    //  Sets M (the value that triggers the MAction).
    //---------------------------------------------------------------------
    public void setM (int m)
    {
        this.M = m;
    }
    
    //---------------------------------------------------------------------
    //  Gets M (the value that triggers the MAction).
    //---------------------------------------------------------------------
    public int getM ()
    {
        return this.M;
    }
    
    //---------------------------------------------------------------------
    //  Sets N (the value that triggers the NAction).
    //---------------------------------------------------------------------
    public void setN (int n)
    {
        this.N = n;
    }
    
    //---------------------------------------------------------------------
    //  Gets N (the value that triggers the NAction).
    //---------------------------------------------------------------------
    public int getN ()
    {
        return this.N;
    }
 
    //*********************************************************************
    //  This class is responsible for not allowing characters other than
    //  digits to be entered, and for not allowing the number of characters
    //  to exceed N.
    //*********************************************************************
    static class NDigitDocument extends PlainDocument
    {
        public void insertString (int offs, String str, AttributeSet a) 
        throws BadLocationException 
        {        
            if (str == null)
                return;
            
            //  Don't allow number of characters to exceed N
            //  (The +1 is because insertString is called before insert/update)
            if (currentLength + 1 > N)
                return;
            
            //  Validate that the characters of the string are digits
            for (int i = 0; i < str.length(); i++) 
            {
                if (!Character.isDigit (str.charAt (i)))
                    return;
            }
            
            super.insertString(offs, str, a);
        }
    }
    
    //---------------------------------------------------------------------
    //  This is necessary for out text field to have the properties 
    //  of the NDigitDocument.
    //---------------------------------------------------------------------
    protected Document createDefaultModel() 
    {
         return new NDigitDocument ();
    }
    
    //*********************************************************************
    //  This class listens to user's interaction with the text field,
    //  and decides what to do based on the number of characters in the 
    //  text field.
    //*********************************************************************
    class MNDocumentListener implements DocumentListener
    {
        //-----------------------------------------------------------------
        //  Called when users insert characters.
        //-----------------------------------------------------------------
        public void insertUpdate (DocumentEvent e) 
        {
            decide (e);
        }
        
        //-----------------------------------------------------------------
        //  Called when users remove characters (DEL or Back Space).
        //-----------------------------------------------------------------
        public void removeUpdate (DocumentEvent e) 
        {
            decide (e);
        }
        
        //-----------------------------------------------------------------
        //  Not called by plain document .
        //  This is used when style changes, but we don't need it here.
        //-----------------------------------------------------------------
        public void changedUpdate (DocumentEvent e) {}

        //-----------------------------------------------------------------
        //  Do an action based on the values of M and N. In our case, the
        //  action is to enable or disable (reaction) the MComponent
        //  and NComponent.
        //-----------------------------------------------------------------
        public void decide (DocumentEvent e) 
        {
            Document doc = (Document)e.getDocument();
            currentLength = doc.getLength ();
            
            //  Enable MComponent if M digits reached
            //  Otherwise, disable it.
            MComponentActor.decide (currentLength == M);
            
            //  Enable NComponent if N digits reached
            //  Otherwise, disable it.
            NComponentActor.decide (currentLength == N);
        }
    }
    
    //---------------------------------------------------------------------
    //  Checks out my work...
    //---------------------------------------------------------------------
    public static void main (String[] args)
    {
        JFrame frame = new JFrame ("Test");
        frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
        
        //  create buttons
        JButton button1 = new JButton ("Button 1");
        JButton button2 = new JButton ("Button 2");
        
        //  Set buttons to be initially disabled
        button1.setEnabled (false);
        button2.setEnabled (false);
        
        //  Set background to white and layout to flow layout
        frame.setBackground (Color.white);
        frame.setLayout (new FlowLayout ());
        
        //  add buttons and text field
        frame.getContentPane().add (new MNDigitField (11, 12, button1, button2, 8));
        frame.getContentPane().add (button1);
        frame.getContentPane().add (button2);
        
        //  Pack and show the window (frame)
        frame.pack();
        frame.setVisible (true);
    }    
}
