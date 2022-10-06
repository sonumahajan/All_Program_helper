setInterval(() => {
    d = new Date();
    htime = d.getHours();
    mtime = d.getMinutes();
    stime = d.getSeconds();
    h_rotation = 30*htime + mtime/2;
    m_rotation = 6*mtime;
    s_rotation = 6*stime;

    hour.style.transform =  `rotate(${h_rotation}deg)`;
    minute.style.transform =  `rotate(${m_rotation}deg)`;
    second.style.transform =  `rotate(${s_rotation}deg)`;
}, 1000);
