import Home from "./Home";
import Contact from "./Contact";

function Content({pageName}){
    if(pageName=="Home"){

    
    return(
        <>
        <Home/>
        </>
    )
    }   
    if(pageName=="Contact"){

    
        return(
            <>
            <Contact/>
            </>
        )
    }
}
export default Content; 