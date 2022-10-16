import React from 'react'
import OptionsCard from './OptionsCard'
function Navbar() {
  return (
    <>
    <div className='fixed top-0 z-50 bg-white w-full shadow-md md:shadow-sm lg:shadow-none'>
        <div className='border mx-8 lg:mx-20 h-14 mt-6 rounded-3xl flex justify-between lg:hidden shadow-md'>
            <div className='flex items-center lg:ml-4 ml-4 space-x-6 search'>
                <img src="/search-red.png" width="15px" alt="" />
                <div>
                    <div className='font-bold text-xs fold'>Where to?</div>
                    <div className='flex space-x-2'>
                        <p className='text-xs fold'>Anywhere</p>
                        <p className='text-xs fold'>Any week</p>
                        <p className='text-xs fold'>Add guests</p>
                    </div>
                </div>
            </div>
            <div className='flex items-center mr-2 border-2 rounded-full my-2 p-2 min-w-fit'>
                <img src="/filters.png" width="15px" alt="" />
            </div>
        </div>
    <div className='border-b-2 hidden lg:block'>
        <div className='flex justify-between mx-20 my-4 items-center'>
        <div className='mr-40 cursor-pointer'>
            <img src="/airbnb.png" width="100px" alt="" />
        </div>
        <div className='flex border-2 px-4 rounded-3xl cursor-pointer shadow-md'>
            <div className='py-3 flex'>

            <div className=' font-semibold border-r-2 px-3 text-sm'>Anywhere</div>
            <div className=' font-semibold border-r-2 px-3 text-sm'>Any week</div>
            <div className='flex space-x-1 px-3 font-light text-sm'>Add guests</div>
            </div>
            <div className=' rounded-full bg-red-500 p-2 my-2 -mr-2'>
                <img src="/search.png" width="15px" alt="" />
            </div>
        </div>
        <div className='flex items-center'>
            <div className=' font-semibold mx-4 cursor-pointer text-sm' >Become a host</div>
            <div className='mr-4 cursor-pointer'>
                <img src="/web.png" width="15px" alt="" />
            </div>
            <div className=' border-2 rounded-3xl cursor-pointer flex items-center px-1 pl-2 py-1 space-x-2'>
                <div className='px-1'>
                    <img src="/menu.png" width="20px" alt="" />
                </div>
                <div>
                    <img src="/user.png" width="35px" alt="" />
                </div>
            </div>
        </div>
        </div>
    </div>
    {/* Options pasted  */}
    <div className='mx-4 lg:mx-20 my-5 lg:my-8 flex space-x-3 lg:overflow-hidden overflow-auto bar '>
        <div className='flex  space-x-1'>
            <OptionsCard title="OMG!" number="1"/>
            <OptionsCard title="National parks" number="2"/>
            <OptionsCard title="Tiny homes" number="3"/>
            <OptionsCard title="Treehouses" number="4"/>
            <OptionsCard title="Beaches" number="5"/>
            <OptionsCard title="Cabins" number="6"/>
            <OptionsCard title="Islands" number="7"/>
            <OptionsCard title="Camping" number="8"/>
            <OptionsCard title="A-frames" number="9"/>
            <OptionsCard title="Design" number="10"/>
            <OptionsCard title="Arctic" number="11"/>
            <OptionsCard title="amazing pools" number="12"/>
            <OptionsCard title="Lakefront" number="13"/>
            <OptionsCard title="Surfing" number="14"/>
        </div>
        <div className='flex items-center space-x-4'>
            <div className='border-2 items-center hidden lg:flex p-1 rounded-full'>
                <img src="/right.png" width="25px" alt="" />
            </div>
            <div className='flex border-2 items-center rounded-xl py-2 px-2 space-x-1'>
                <img src="/filters.png" width="15px" alt="" />
                <div className='pr-4 lg:pr-0'>Filters</div>
            </div>
        </div>
    </div>
    </div>
    </>
  )
}

export default Navbar