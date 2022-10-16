import React from 'react'

function Map() {
  return (
    <div className='flex items-center justify-center'>
    <div className='lg:fixed cursor-pointer hidden lg:flex items-center bottom-20'>
        <div className='flex bg-[#222222] hover:shadow-lg justify-center px-4 py-3 items-center space-x-2  rounded-full'>
            <div className=' text-white font-semibold'>
                Show map
            </div>
            <div className='text-white '>
                <img src="/map.png" width="15px" alt="" />
            </div>
        </div>
    </div>
    </div>
  )
}

export default Map