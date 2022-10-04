import React from 'react'
function Cards() {
  return (
    <div className='md:w-80 lg:w-72 w-auto m-6 mb-10 cursor-pointer'>
        <div className='w-full rounded-xl mb-2'>
            <img className='rounded-xl' src="/photo.jpg" width="500px" height="500px" alt="" />
        </div>
        <div>
            <div className='flex justify-between'>
                <div className=' font-semibold'>
                    New Delhi, India
                </div>
                <div>
                    ★ 4.88
                </div>
            </div>
            <div className='font-light'>4,758 Kilometers</div>
            <div className='font-light'>9-14 Jul</div>
            <div className='flex'><p className=' font-semibold'>₹30,271 </p>&nbsp;night</div>
        </div>
    </div>
  )
}

export default Cards