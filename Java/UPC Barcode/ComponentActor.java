import javax.swing.*;

//***************************************************************************
// This is a class that performs actions and reactions on a Jcomponent.
// For example, it might make a text area as editable or non-editable.
//    
// Author: Ali Badereddin
// Date:   September 11, 2005
//
//***************************************************************************
public class ComponentActor extends Actor
{
    //  Define the action types that are specific for the component actor
    public final static int ENABLE = 0;        //  Enable or disable a component
    public final static int MAKE_VISIBLE = 1;  //  Show or hide a component
    
    //  Represents hte component that the actor acts on.
    private JComponent component;
    
    //---------------------------------------------------------------------
    //  Constructor...
    //---------------------------------------------------------------------
    public ComponentActor (JComponent c)
    {
        //  Get component
        component = c;
        
        //  Set initial action type to ENABLE
        actionType = ENABLE;
    }
    
    //---------------------------------------------------------------------
    //  Perform an action.
    //---------------------------------------------------------------------
    public void doAction () 
    { 
        //  Do nothing if no component is supplied
        if (component == null)
            return;
            
        //  Perform action based on action type
        switch (actionType)
        {
            case ENABLE:
                component.setEnabled (true);
                break;
            case MAKE_VISIBLE:
                component.setVisible (true);
                break;
        }
    }
    
    //---------------------------------------------------------------------
    //  Reverse the action..
    //---------------------------------------------------------------------
    public void undoAction ()  
    { 
        //  Do nothing if no component is supplied
        if (component == null)
            return;
            
        //  Perform reaction based on action type
        switch (actionType)
        {
            case ENABLE:
                component.setEnabled (false);
                break;
            case MAKE_VISIBLE:
                component.setVisible (false);
                break;
        }
    }
    
    //---------------------------------------------------------------------
    //  Change component.
    //---------------------------------------------------------------------
    public void setComponent (JComponent c)
    {
        component = c;
    }
    
    //---------------------------------------------------------------------
    // Get component.
    //---------------------------------------------------------------------
    public JComponent getComponent ()
    {
        return component;
    }
    
    //---------------------------------------------------------------------
    //  Set action type...
    //---------------------------------------------------------------------
    public void setActionType (int at)
    {
        actionType = at;
    }
    
    //---------------------------------------------------------------------
    //  Get action type...
    //---------------------------------------------------------------------
    public int getActionType ()
    {
        return actionType;
    }
}
