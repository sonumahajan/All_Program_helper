import { Box, Typography } from "@mui/material";
import React from "react";

const About = () => {
  return (
    <div>
      
      <Box display="flex" flexDirection="column" alignItems="center">
        <Typography sx={{ fontFamily: "fantasy" }} variant="h4">
          This is Web Book Store where you can find your favourite books at the best prices!!
        </Typography>
        <Typography sx={{ fontFamily: "fantasy", marginTop:"30%" }} variant="h4">
          Made by Shubham Kumar
        </Typography>
        <Typography sx={{ fontFamily: "fantasy", marginBottom:"100%"}} variant="h4">
          💕
        </Typography>
      </Box>
    </div>
  );
};

export default About;
