import java.awt.*;
import javax.swing.*;

//***************************************************************************
// Represents the panel where the Barcode is drawn. 
//    
// Author: Ali Badereddin
// Date:   September 09, 2005
//
//***************************************************************************
public class BarcodeLabel extends JPanel
{
	private static final long serialVersionUID = 5057456390763995907L;

	//  Put infront and at end of every barcode
	private final String quiteZone = "000000000";
    
    //  Put after quite zone at the front
	private final String leftStartCode = "101";
    
    //  Put before quite zone at the end
	private final String rightEndCode = "101";
    
    //  Put in the center of every barcode
	private final String centerCode = "01010";
    
    //  Represent the left UPC bits for the digits
	private final String leftCodes[] = {"0001101", "0011001", "0010011", "0111101", 
		                                "0100011", "0110001", "0101111", "0111011", 
		                                "0110111", "0001011"};
    
    //  Represent the right UPC bits for the digits
	private final String rightCodes[] = {"1110010", "1100110", "1101100", "1000010",
		                                 "1011100", "1001110", "1010000", "1000100",
		                                 "1001000", "1110100"};
    
    //  represents the number of slices in a UPC-A
	private final int sliceNum = 113;      // 3 + 3 + 5 + (12 * 7) + (9 * 2) = 113

	private String UPC;       //  UPC to be converted into barcode
	private String barcode;   //  the barcode
	private boolean valid;    //  UPC is valid or not?
	private Color barColor;   //  The color of the slice corresponding to bit 1
	private Color spaceColor; //  The color of the slice corresponding to bit 0
	private Color errorColor; //  In case the bit is neither 0 or 1 (something wrong)
	private int x;            //  Represents the current x coordinate of the slice
	private int sliceWidth;   //  Represents the width of the slice
	private int width;        //  Width of barcode label
	private int height;       //  height of barcode label
    
    //---------------------------------------------------------------------
    //  Constructor... 
    //  
    //  sw is the slice width and sh is the slice height.
    //  bc is the bar color, sc is the space color, and ec is error color.
    //---------------------------------------------------------------------
    public BarcodeLabel (int sw, int sh, Color bc, Color sc, Color ec)
    {
        //  Upc is initially invalid
        valid = false;
        
        //  Set x initially to zero
        x = 0;
        
        //  Set the slicewidth
        sliceWidth = sw;
        
        //  Set the width of barcode label
        width = sliceNum * sw;
        
        //  Set the height of barcode label
        height = sh;
        
        //  Set the colors
        barColor = bc;
        spaceColor = sc;
        errorColor = ec;
        
        //  Set the background color to space color
        this.setBackground (spaceColor);
        
        //  Set the preferred size of the barcode label
        this.setPreferredSize (new Dimension (width, height));
    }
    
    //---------------------------------------------------------------------
    //  Paints the barcode only if it is valid...
    //---------------------------------------------------------------------
    public void paintComponent (Graphics page)
    {
        super.paintComponent (page);
        
        //  Clear the barcode before drawing
        page.setColor (getBackground ());
        page.fillRect (0, 0, width, height);
        
        //  Draw the barcode only if the UPC is valid
        if (isValid ())
            drawBarcode (page);
    }
    
    //---------------------------------------------------------------------
    //  Draws the barcode if it is not null.
    //---------------------------------------------------------------------
    public void drawBarcode (Graphics page)
    {
        int barcodeLength;
        
        //  Set x to zero
        x = 0;
        
        if (barcode != null)
        {
            //  Get the barcode length
            barcodeLength = barcode.length ();
            
            //  Loop over every character (0 or 1)
            for (int i = 0; i < barcodeLength; i++)
            {
                //  Draw a white slice for the 0
                if (barcode.charAt (i) == '0')
                {
                    page.setColor (spaceColor);
                }
                //  Draw a black slice for the '1'
                else if (barcode.charAt (i) == '1')
                {
                    page.setColor (barColor);
                }
                //  Draw a red slice to show something graphically
                else
                {
                    page.setColor (errorColor);
                }
                
                //  Update the coordinates
                x += sliceWidth;
                
                //  Draw the slices at the specified coordinates
                page.fillRect (x, 0, sliceWidth, height);
            }
        }      
    }
    
    //---------------------------------------------------------------------
    //  Set the UPC that will be converted into barcode.
    //---------------------------------------------------------------------
    public void setUPC (String c)
    {
        UPC = c;
    }
    
    //---------------------------------------------------------------------
    //  Get the UPC that will be converted into barcode.
    //---------------------------------------------------------------------
    public String getUPC ()
    {
        return UPC;
    }
    
    //---------------------------------------------------------------------
    //  Checks if the UPC is valid. a UPC is valid if it consists
    //  of exactly 12 digits.
    //---------------------------------------------------------------------
    public void validateUPC ()
    {
        valid = UPC.matches ("[0-9]{12}?");
    }
    
    //---------------------------------------------------------------------
    //  Tells whether that UPC is valid.
    //---------------------------------------------------------------------
    public boolean isValid ()
    {
        return valid;
    }
    
    //---------------------------------------------------------------------
    //  Sets valid to v.
    //---------------------------------------------------------------------
    public void setValid (boolean v)
    {
        valid = v;
        repaint ();
    }
    
    //---------------------------------------------------------------------
    //  Helper function to convert a character to an integer.
    //---------------------------------------------------------------------
    public int charToInteger (char c)
    {
        return c - 48;
    }
    
    //---------------------------------------------------------------------
    //  Generate the barcode from the UPC...
    //---------------------------------------------------------------------
    public void generateBarcode ()
    {
        if (isValid ())
        {
            barcode = quiteZone + leftStartCode + 
                      leftCodes[charToInteger (UPC.charAt (0))] + 
                      leftCodes[charToInteger (UPC.charAt (1))] + 
                      leftCodes[charToInteger (UPC.charAt (2))] + 
                      leftCodes[charToInteger (UPC.charAt (3))] + 
                      leftCodes[charToInteger (UPC.charAt (4))] + 
                      leftCodes[charToInteger (UPC.charAt (5))] +
                      centerCode +
                      rightCodes[charToInteger (UPC.charAt (6))] + 
                      rightCodes[charToInteger (UPC.charAt (7))] + 
                      rightCodes[charToInteger (UPC.charAt (8))] + 
                      rightCodes[charToInteger (UPC.charAt (9))] + 
                      rightCodes[charToInteger (UPC.charAt (10))] + 
                      rightCodes[charToInteger (UPC.charAt (11))] +
                      rightEndCode + quiteZone;
        
            repaint ();
        }
    }
    
    //---------------------------------------------------------------------
    //  Checks out my work...
    //---------------------------------------------------------------------
    public static void main (String[] args)
    {
        JFrame frame = new JFrame ("Test");
        frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
        
        //   Create barcode
        BarcodeLabel barcodeLabel = new BarcodeLabel (4, 200, Color.blue, Color.yellow, Color.red);
        
        //  Set the UPC of the barcode label
        barcodeLabel.setUPC ("314159265358");
        
        //  Check the UPC of the barcode label
        barcodeLabel.validateUPC ();
        
        //  Create the barcode
        barcodeLabel.generateBarcode ();
        
        frame.setBackground (Color.white);
        frame.getContentPane().add (barcodeLabel);
        frame.pack();
        frame.setVisible (true);
    } 
}
