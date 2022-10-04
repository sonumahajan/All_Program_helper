import React from 'react'
function Footer() {
  return (
    <div className='fixed bottom-0 border-t-2 w-full py-3 z-50 bg-white'>
        <div className='lg:flex justify-between mx-20 hidden'>
            <div className='flex space-x-2 cursor-pointer'>
                <div>© 2022 Airbnb, Inc.</div>
                <div>·</div>
                <div>Privacy</div>
                <div>·</div>
                <div>Terms</div>
                <div>·</div>
                <div>Sitemap</div>
                <div>·</div>
                <div>Company details</div>
                <div>·</div>
                <div>Destinations</div>
            </div>
            <div className='flex space-x-6'>
                <div className='flex items-center space-x-2'>
                    <img src="/web.png" width="15px" alt="" />
                    <div className='font-semibold cursor-pointer'>English (IN)</div>
                </div>
                <div className='font-semibold cursor-pointer'>₹ INR</div>
                <div className=' items-center flex space-x-3'>
                    <div className='font-semibold cursor-pointer'>Support & resources</div>
                    <img src="/up.png" width="10px" alt="" />
                </div>
            </div>
        </div>
        <div className='flex lg:hidden items-center justify-center space-x-8'>
            <div className=' items-center flex-col flex'>
                <img src="/search-red.png" width="20px" height="20px" alt="" />
                <div className='font-semibold text-xs'>Explore</div>
            </div>
            <div className=' items-center flex-col flex'>
                <img src="/heart-grey.png" width="20px" alt="" />
                <div className='font-semibold text-xs'>Wishlist</div>
            </div>
            <div className=' items-center flex-col flex'>
                <img src="/user-grey.png" width="20px" alt="" />
                <div className='font-semibold text-xs'>Login</div>
            </div>
        </div>
    </div>
  )
}

export default Footer