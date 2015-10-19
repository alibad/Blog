import javax.swing.*;
import java.awt.*;

//***************************************************************************
// This class is responsible for running the Bar-code program.
//    
// Author: Ali Badereddin 
// Date:   September 09, 2005
//
//***************************************************************************
public class Main
{   
    //---------------------------------------------------------------------
    //  Run program...
    //---------------------------------------------------------------------
    public static void main (String[] args)
    {
        //  Declare icon image
        Image titleBarIcon = Toolkit.getDefaultToolkit().getImage ("images/titleBarIcon.jpg");
        
        //  Make sure we have nice window decorations.
        JFrame.setDefaultLookAndFeelDecorated(true);

        //  Create and set up the window.
        JFrame frame = new JFrame("ASTI SPUMANTE BAR-CODE");
        frame.setDefaultCloseOperation (JFrame.EXIT_ON_CLOSE);
        
        //  Set the icon for the frame
        frame.setIconImage (titleBarIcon);
        
        //  Create and set up the content pane.
        JComponent newContentPane = new UpcBarcode ();
        newContentPane.setOpaque(true); //  content panes must be opaque
        frame.setContentPane(newContentPane);
        
        //  Display the window.
        frame.pack();
        frame.setVisible (true);
    }    
}