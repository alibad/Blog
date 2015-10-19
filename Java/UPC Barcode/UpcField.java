import java.awt.*;
import javax.swing.*;

//***************************************************************************
// This is the text field were the user enters the UPC-A code.
//    
// Author: Ali Badereddin
// Date:   September 09, 2005
//
//***************************************************************************
public class UpcField extends MNDigitField
{   
	private static final long serialVersionUID = -9056775353920507447L;

	//---------------------------------------------------------------------
    //  Create a field were user enters UPC code.
    //---------------------------------------------------------------------
    public UpcField (JButton MButton, JButton NButton)
    {
        //  Create a 12 digit field having width of 8 cols
        //  M = 11, N = 12, MComponent = MButton, NComponent = NButton
        //  cols = 8.
        super (11, 12, MButton, NButton, 8);    
    }
    
    //---------------------------------------------------------------------
    //  Generates check digit and appends it to the upc field.
    //---------------------------------------------------------------------
    public void generateCheckDigit ()
    {
        //  Generate check digit only if there are 11 characters
        if (this.howManyDigits () == 11)
        {
            String upc = this.getText ();
            int checksum = 0;
            
            checksum = generateCheckDigit (upc);
            
            //  Append the check digit to the end of the UPC
            this.setText (upc + checksum);
        }
    }
    
    //---------------------------------------------------------------------
    //  Generates check digit.
    //---------------------------------------------------------------------
    public int generateCheckDigit (String upc)
    {
        int checksum = 0;
            
        for (int i = 1; i <= upc.length (); i++)
        {
            // even
            if (i % 2 == 0)
                checksum += charToInteger (upc.charAt (i - 1)) * 1;
            //  odd
            else
                checksum += charToInteger (upc.charAt (i - 1)) * 3;
        }
        
        return ( 10 - ( checksum % 10 )  ) % 10;
    }
    
    //---------------------------------------------------------------------
    //  Makes sure that the check digit is valid.
    //---------------------------------------------------------------------
    public boolean isCheckDigitValid ()
    {
        if (howManyDigits () == 12)
        {
            String upc = this.getText ();
            
            //  The check digit entered by the user
            //  character 12 (start at 0)
            int checkDigitEntered = charToInteger (upc.charAt (11));  
            
            //  the generate (valid) check digit
            int validCheckDigit = this.generateCheckDigit (upc.substring (0, 11));
            
            return checkDigitEntered == validCheckDigit;
        }
        
        return false;
    }
    
    //---------------------------------------------------------------------
    //  Helper function to convert a character to an integer.
    //---------------------------------------------------------------------
    public int charToInteger (char c)
    {
        return c - 48;
    }
    
    //---------------------------------------------------------------------
    //  Set the UPC.
    //---------------------------------------------------------------------
    public void setUPC (String upc)
    {
        setText (upc);
    }
    
    //---------------------------------------------------------------------
    //  Get the UPC.
    //---------------------------------------------------------------------
    public String getUPC ()
    {
        return getText ();
    }

    //---------------------------------------------------------------------
    //  Checks out my work...
    //---------------------------------------------------------------------
    public static void main (String[] args)
    {
        JFrame frame = new JFrame ("UPC-A Field");
        frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
        
        //  create buttons
        JButton button1 = new JButton ("Generate Check Digit");
        JButton button2 = new JButton ("Generate Bar Code");
        
        //  Set buttons to be initially disabled
        button1.setEnabled (false);
        button2.setEnabled (false);
        
        //  Set background to white and layout to flow layout
        frame.setBackground (Color.white);
        frame.setLayout (new FlowLayout ());
        
        //  add buttons and text field
        frame.getContentPane().add (new UpcField (button1, button2));
        frame.getContentPane().add (button1);
        frame.getContentPane().add (button2);
        
        //  Pack and show the window (frame)
        frame.pack();
        frame.setVisible (true);
    }   
}
