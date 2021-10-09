//
// @brief   
// @details 
// @author  Steffen Peikert (ch3ll)
// @email   Horizon@ch3ll.com
// @version 1.0.0
// @date    17/10/2020 16:17
// @project Horizon
//


#pragma once

namespace HORIZON::RENDERAPI
{
    // TODO: shared from this?
    class RenderAPI
    {
    public:
        /*!
         * @brief The returning function pointer for the specified function name
         */
        using APIFunctionPointer = void (*)();
        /*!
         * @brief The API function loader. Requires a function name or identifier and returns the corresponding function pointer.
         */
        using APIFunctionLoader = APIFunctionPointer (*)(char const*);

    public:
        /*!
         * @brief Initialises the render api. This is guaranteed to be called on the thread with the context.
         * @param loader The api function loader provided by the window library. If no loader is available, nullptr is a valid parameter as well.
         * @return True if the api was initialised successfully.
         */
        virtual bool Initialise(APIFunctionLoader&& loader) noexcept = 0;

        virtual void Destroy() noexcept
        { }


        /*!
         * @brief Callback when the context changes the thread owner. This will be called on the new thread.
         */
        virtual void OnNewThread() noexcept = 0;

        /*!
         * @brief Callback when the context changes the thread owner. This will be called on the releasing thread.
         */
        virtual void OnThreadRelease() noexcept = 0;

        /*!
         * @brief Makes this context the current global context.
         */
        virtual void MakeGlobal() noexcept = 0;

        // TODO: get global context?
    };
}
