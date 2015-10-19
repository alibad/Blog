import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

//***************************************************************************
// This is the main panel... 
//    
// Author: Ali Badereddin
// Date:   September 09, 2005
//
//***************************************************************************
public class UpcBarcode extends JPanel
{
	private static final long serialVersionUID = 5621128756578917138L;

	//  Represents the orange color used at code project
    private final Color codeProjectOrange = new Color (255, 153, 0);
    
    //  Declare the barcode label
    private BarcodeLabel barcodeLabel;
    
    //  Declare the panel that will hold the barcode label
    private JPanel barcodePanel;
    
    //  Declare the buttons
    private JButton generateCheckDigitButton;
    private JButton generateBarcodeButton;
    
    //  Declare the panel that will hold the buttons
    private JPanel buttonPanel;
    
    //  Declare the UPC field
    private UpcField upcField;
    
    //  Declare the panel that will hold the UPC field
    private JPanel upcPanel;
    
    //*********************************************************************
    //  Contructor.
    //*********************************************************************
    public UpcBarcode ()
    {     
        //  Create the Barcode Label with a slice width of 2 pixels and a
        //  slice height of 150 pixels.
        barcodeLabel = new BarcodeLabel (2, 150, Color.black, codeProjectOrange, Color.red);
        
        //  Create the barcode panel and add the barcode label to it
        barcodePanel = new JPanel ();
        barcodePanel.add (barcodeLabel);
        
        //  Create the buttons
        generateCheckDigitButton = new JButton ("Generate Check Digit");
        generateBarcodeButton    = new JButton ("Generate Bar Code");
        
        //  Set the buttons background color to orange
        generateCheckDigitButton.setBackground (codeProjectOrange);
        generateCheckDigitButton.setOpaque(true);
        generateBarcodeButton.setBackground (codeProjectOrange);
        generateBarcodeButton.setOpaque(true);
        
        //  Add action listeners to the buttons
        generateCheckDigitButton.addActionListener (new CheckDigitListener ());
        generateBarcodeButton.addActionListener (new BarcodeListener ());
        
        //  The buttons are initially disabled
        generateCheckDigitButton.setEnabled (false);
        generateBarcodeButton.setEnabled (false);
        
        //  Add the buttons to the panel
        buttonPanel = new JPanel ();
        buttonPanel.add (generateCheckDigitButton);
        buttonPanel.add (generateBarcodeButton);
        
        //  Create the UPC field
        upcField = new UpcField (generateCheckDigitButton, generateBarcodeButton);
        upcField.setBackground (codeProjectOrange);
        
        //  Create the UPC panel and add the upc field to it
        upcPanel = new JPanel ();
        JLabel enterUPCLabel = new JLabel ("Enter UPC ");
        enterUPCLabel.setForeground (codeProjectOrange);
        upcPanel.add (enterUPCLabel);
        upcPanel.add (upcField);
        
        //  Set the layout of the main panel to BorderLayout
        setLayout (new BorderLayout ());
        
        //  Set the color of the panels
        upcPanel.setBackground (Color.black);
        barcodePanel.setBackground (Color.black);
        buttonPanel.setBackground (Color.black);
        
        //  Add the upc field in the North
        add (upcPanel, BorderLayout.NORTH);
        
        //  Add the barcode label at the center
        add (barcodePanel, BorderLayout.CENTER);
        
        //  Add the buttons in the South
        add (buttonPanel, BorderLayout.SOUTH);
    }
    
    //*********************************************************************
    //  Generates the check digit of the UPC-A.
    //*********************************************************************
    private class CheckDigitListener implements ActionListener
    {
        public void actionPerformed (ActionEvent e)
        {
            //  Generate the check digit and append it at the end of the
            //  UPC field.
            upcField.generateCheckDigit ();
        }
    }
    
    //*********************************************************************
    //  Generates the barcode based on the UPC-A.
    //*********************************************************************
    private class BarcodeListener implements ActionListener
    {
        public void actionPerformed (ActionEvent e)
        {
            //  Generate the barcode only if the check digit is valid
            if (upcField.isCheckDigitValid ())
            {
                //  Set the UPC of the barcode label
                barcodeLabel.setUPC (upcField.getUPC());
                
                //  Validate the UPC of the barcode label
                barcodeLabel.validateUPC ();
                
                //  Generate the barcode
                barcodeLabel.generateBarcode ();
                
                //  Select the text in the upc field
                upcField.selectAll ();
            }
            else
            {
                //  Make the barcode as invalid so that nothing would be
                //  drawn on the barcode panel.
                //  Check BarcodeLabel.paintComponent
                barcodeLabel.setValid (false);
            }
        }
    }
    
    //---------------------------------------------------------------------
    //  Check out my work..
    //---------------------------------------------------------------------
    public static void main (String[] args)
    {
        //  Create and set up the window.
        JFrame frame = new JFrame("ASTI SPUMANTE BAR-CODE");
        frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add (new UpcBarcode ());
        
        //  Display the window.
        frame.pack();
        frame.setVisible (true);
    } 
}
