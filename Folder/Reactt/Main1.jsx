import { useState } from "react";
import "./main1.css"
import Content from "./Content.jsx"
function Main1(){
    let [page,setPage]=useState("Home");
    function changePage(event){
        setPage(event.target.id)
    }
     return(
        <>
        <div className="container">
            <div className="sidebar">
                <button id="Home" onClick={changePage}>Home</button>
                <button id = "Contact" onClick={changePage}>Contact</button>
            </div>
            <div className="maincontent">
            <Content pageName={page}/>
            </div>
        </div>
        </>
     )
}
export default Main1;