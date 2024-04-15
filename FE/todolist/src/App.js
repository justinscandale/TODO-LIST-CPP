import "./App.css";

function App() {
    return (
        <div className="relative flex items-center justify-center min-h-screen">
            <div className="w-full flex flex-col items-center">
                <div className="text-4xl font-semibold m-10">Todo List</div>
                <div className="">
                    <div>
                        <div className="flex">
                            <div className="flex flex-col">
                                <input
                                    type="text"
                                    placeholder="Add a task"
                                    className="w-96 p-3 border border-gray-400 border-radius-3"
                                />
                                <input
                                    type="text"
                                    placeholder="Optional Description"
                                    className="w-96 p-3 border border-gray-400 border-radius-3"
                                />
                            </div>
                            <div className="flex flex-col">
                                <select
                                    name="status"
                                    id="status"
                                    className="p-3 border border-gray-400 border-radius-3"
                                >
                                    <option value="-1">Priority</option>
                                    <option value="0">High</option>
                                    <option value="1">Medium</option>
                                    <option value="2">Low</option>
                                </select>
                                <button className="border-1 border-gray-400">
                                    <svg
                                        xmlns="http://www.w3.org/2000/svg"
                                        className="h-16 w-16"
                                        fill="none"
                                        viewBox="0 0 24 24"
                                        stroke="currentColor"
                                    >
                                        <path
                                            strokeLinecap="round"
                                            strokeLinejoin="round"
                                            strokeWidth={2}
                                            d="M12 6v6m0 0v6m0-6h6m-6 0H6"
                                        />
                                    </svg>
                                </button>
                            </div>
                        </div>
                    </div>
                </div>
                <div className="mt-10">
                    <table className="divide-y divide-gray-200">
                        <thead className="bg-gray-50">
                            <tr>
                                <th
                                    scope="col"
                                    className="px-6 py-3 text-left text-sm font-medium text-gray-500 uppercase tracking-wider"
                                >
                                    #
                                </th>
                                <th
                                    scope="col"
                                    className="px-6 py-3 text-left text-sm font-medium text-gray-500 uppercase tracking-wider"
                                >
                                    Todo Item
                                </th>
                                <th
                                    scope="col"
                                    className="px-6 py-3 text-left text-sm font-medium text-gray-500 uppercase tracking-wider"
                                >
                                    Status
                                </th>
                                <th
                                    scope="col"
                                    className="px-6 py-3 text-center text-sm font-medium text-gray-500 uppercase tracking-wider"
                                >
                                    Actions
                                </th>
                            </tr>
                        </thead>
                        <tbody className="bg-white divide-y divide-gray-200">
                            <tr key={1}>
                                <td className="px-6 py-4 whitespace-nowrap">
                                    <div className="text-md text-gray-900">
                                        1
                                    </div>
                                </td>
                                <td className="px-6 py-4 whitespace-nowrap">
                                    <div className="flex items-center">
                                        <div className="ml-4">
                                            <div className="text-md font-medium text-gray-900">
                                                Buy Grocies
                                            </div>
                                            <div className="text-sm text-gray-500">
                                                Orange Juice, Peanut Butter, and
                                                Tissues
                                            </div>
                                        </div>
                                    </div>
                                </td>
                                <td className="px-6 py-4 whitespace-nowrap">
                                    <div className="text-md text-gray-900">
                                        In Progress
                                    </div>
                                </td>
                                <td className="px-6 py-4 whitespace-nowrap">
                                    <div className="text-md text-gray-900">
                                        <button className="inline-flex items-center mr-5 px-4 py-2 border border-transparent shadow-sm text-sm font-medium hover:underline rounded-md text-white bg-blue-600 hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500">
                                            Finished
                                        </button>
                                        <button className="inline-flex items-center px-4 py-2 border border-transparent shadow-sm text-sm font-medium hover:underline rounded-md text-white bg-blue-600 hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500">
                                            Delete
                                        </button>
                                    </div>
                                </td>
                            </tr>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    );
}

export default App;
