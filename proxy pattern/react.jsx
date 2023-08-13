import React, { useState } from 'react';

// real object
function RealImage({ filename }) {
    console.log("Loading image")
    return <img src="image_url" alt={filename} />;
}


// proxy component
function ImageProxy({ filename }) {
    const [realImage, setRealImage] = useState(null);
    const displayImage = () => {
        if (!realImage) {
            setRealImage(<RealImage filename={filename} />);
        }
    }

    return (
        <div>
            <button onClick={displayImage}>Display Image</button>
            {realImage}
        </div>
    )
}


// Image gallery component
function ImageGallery() {
    return (
        <div>
            <h2> Gallery </h2>
            <ImageProxy filename={"abc.png"} />
            <ImageProxy filename={"xyz.png"} />
            <ImageProxy filename={"dfg.png"} />
        </div>
    )
}


//App
function App() {
    return <ImageGallery />
}

export default App;