//***************************************************************************
// This is a class that performs actions and reactions.
//    
// Author: Ali Badereddin
// Date:   September 11, 2005
//
//***************************************************************************
public abstract class Actor
{
	protected int actionType;
    
    //---------------------------------------------------------------------
    //  Perform an action.
    //---------------------------------------------------------------------
    public void doAction () { }
    
    //---------------------------------------------------------------------
    //  Reverse the action.
    //---------------------------------------------------------------------
    public void undoAction ()  { }
    
    //---------------------------------------------------------------------
    //  Act or react  based on condition.
    //---------------------------------------------------------------------
    public void decide (boolean condition)
    {
        if (condition)
            doAction ();
        else
            undoAction ();
    }
}
