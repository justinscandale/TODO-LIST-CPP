import React, { useEffect, useState } from "react";
import Link from 'next/link'
import axios from "axios"
import { useRouter } from "next/router";
import local from "../local.json"

const host = process.env.NEXT_PUBLIC_HOST;

export default function FeaturedCompanies({ companyName }) {
    const locale = useRouter().locale
    const [companies, setCompanies] = useState(null)

    const fetchData = () => {
        if (companyName === "" || companyName === undefined) {
            axios.get(host + "/companies/wd").then(res => {
                const displayableCompanies = []
                res.data.forEach(company => {
                    displayableCompanies.push({
                        companyName: company.companyName.charAt(0).toUpperCase() + company.companyName.slice(1),
                        companyEmail: company.companyEmail,
                        companySector: company.companySector.charAt(0).toUpperCase() + company.companySector.slice(1),
                        // Can edit logo abit here
                        companyLogo: company.companyLogo,
                        companyPrice: company.companyPrice.toString() + " " + "ETB",
                        companyExchangeScore: company.companyExchangeScore.toString() + "%",
                    })
                })
                setCompanies(displayableCompanies)
            })
        } else {
            setCompanies(null)
            axios.post(host + "/companies/getCompanyByName", { companyName }).then(res => {
                const displayableCompanies = []
                if (!res.data.found) {
                    setCompanies("Not Found")
                    return
                }
                res.data.company.forEach(company => {
                    displayableCompanies.push({
                        companyName: company.companyName.charAt(0).toUpperCase() + company.companyName.slice(1),
                        companyEmail: company.companyEmail,
                        companySector: company.companySector.charAt(0).toUpperCase() + company.companySector.slice(1),
                        // Can edit logo abit here
                        companyLogo: company.companyLogo,
                        companyPrice: company.companyPrice.toString() + " " + "ETB",
                        companyExchangeScore: company.companyExchangeScore.toString() + "%",
                    })
                })
                setCompanies(displayableCompanies)
            })
        }
        console.log(process);
        console.log(companies)
    }

    useEffect(() => { fetchData() }, [companyName])

    return (

        <div className="flex flex-col mt-12 lg:mx-12 mx-4">
            <div className="mb-4 text-xl">{(locale == "en") ? "Featured Companies" : local["index"]["Featured Companies"]}</div>
            <div className="-my-2 overflow-x-auto sm:-mx-6 lg:-mx-8">
                <div className="py-2 align-middle inline-block min-w-full sm:px-6 lg:px-8">
                    <div className="shadow overflow-hidden border-b border-gray-200 sm:rounded-lg">
                        <table className="min-w-full divide-y divide-gray-200">
                            <thead className="bg-gray-50">
                                <tr>
                                    <th
                                        scope="col"
                                        className="px-6 py-3 text-left text-sm font-medium text-gray-500 uppercase tracking-wider"
                                    >
                                        {(locale == "en") ? "Name" : local["index"]["Name"]}
                                    </th>
                                    <th
                                        scope="col"
                                        className="px-6 py-3 text-left text-sm font-medium text-gray-500 uppercase tracking-wider"
                                    >
                                        {(locale == "en") ? "Sector" : local["index"]["Sector"]}
                                    </th>
                                    <th
                                        scope="col"
                                        className="px-6 py-3 text-left text-sm font-medium text-gray-500 uppercase tracking-wider"
                                    >
                                        {(locale == "en") ? "Price" : local["index"]["Price"]}
                                    </th>
                                    <th
                                        scope="col"
                                        className="px-6 py-3 text-center text-sm font-medium text-gray-500 uppercase tracking-wider"
                                    >
                                        {(locale == "en") ? "Exchange Score" : local["index"]["Exchange Score"]}
                                    </th>
                                    <th scope="col" className="relative px-6 py-3">
                                        <span className="sr-only">{(locale == "en") ? "Exchange" : local["index"]["Exchange"]}</span>
                                    </th>
                                </tr>
                            </thead>
                            <tbody className="bg-white divide-y divide-gray-200">
                                {(companies) ? (
                                    (companies !== "Not Found") ? (
                                        companies && companies.map((company, index) => (
                                            <tr key={index}>
                                                <td className="px-6 py-4 whitespace-nowrap">
                                                    <div className="flex items-center">
                                                        <div className="flex-shrink-0 h-10 w-10">
                                                            <img className="h-11 w-11" src={company.companyLogo} alt="" />
                                                        </div>
                                                        <div className="ml-4">
                                                            <div className="text-md font-medium text-gray-900">{company.companyName}</div>
                                                            <div className="text-sm text-gray-500">{company.companyEmail}</div>
                                                        </div>
                                                    </div>
                                                </td>
                                                <td className="px-6 py-4 whitespace-nowrap">
                                                    <div className="text-md text-gray-900">{company.companySector}</div>
                                                </td>
                                                <td className="px-6 py-4 whitespace-nowrap">
                                                    <div className="text-md text-gray-900">{company.companyPrice}</div>
                                                </td>
                                                <td className="px-6 py-4 text-center">{company.companyExchangeScore}</td>
                                                <td className="px-6 py-4 whitespace-nowrap text-md text-center font-medium">
                                                    <button className="inline-flex items-center px-4 py-2 border border-transparent shadow-sm text-sm font-medium hover:underline rounded-md text-white bg-blue-600 hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500">
                                                        <Link href="/main/">
                                                            Exchange
                                                        </Link>
                                                    </button>
                                                </td>
                                            </tr>
                                        ))
                                    ) : (
                                        // TODO: Fix this not found case
                                        <div className="m-5">
                                            <div className="flex justify-between">
                                                <span className="text-lg">{(locale == "en") ? "Not Found" : local["index"]["Not Found"]}</span>
                                                <span>{(locale == "en") ? "Try checking the spelling." : local["index"]["Try checking the spelling."]}</span>
                                                <svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke="currentColor" stroke-width="2">
                                                    <path stroke-linecap="round" stroke-linejoin="round" d="M10 14l2-2m0 0l2-2m-2 2l-2-2m2 2l2 2m7-2a9 9 0 11-18 0 9 9 0 0118 0z" />
                                                </svg>
                                            </div>

                                        </div>
                                    )
                                ) : (
                                    <div className="text-center">
                                        <svg role="status" className="inline w-10 h-10 mr-2 text-gray-200 animate-spin dark:text-gray-600 fill-blue-600" viewBox="0 0 100 101" fill="none" xmlns="http://www.w3.org/2000/svg">
                                            <path d="M100 50.5908C100 78.2051 77.6142 100.591 50 100.591C22.3858 100.591 0 78.2051 0 50.5908C0 22.9766 22.3858 0.59082 50 0.59082C77.6142 0.59082 100 22.9766 100 50.5908ZM9.08144 50.5908C9.08144 73.1895 27.4013 91.5094 50 91.5094C72.5987 91.5094 90.9186 73.1895 90.9186 50.5908C90.9186 27.9921 72.5987 9.67226 50 9.67226C27.4013 9.67226 9.08144 27.9921 9.08144 50.5908Z" fill="currentColor"></path>
                                            <path d="M93.9676 39.0409C96.393 38.4038 97.8624 35.9116 97.0079 33.5539C95.2932 28.8227 92.871 24.3692 89.8167 20.348C85.8452 15.1192 80.8826 10.7238 75.2124 7.41289C69.5422 4.10194 63.2754 1.94025 56.7698 1.05124C51.7666 0.367541 46.6976 0.446843 41.7345 1.27873C39.2613 1.69328 37.813 4.19778 38.4501 6.62326C39.0873 9.04874 41.5694 10.4717 44.0505 10.1071C47.8511 9.54855 51.7191 9.52689 55.5402 10.0491C60.8642 10.7766 65.9928 12.5457 70.6331 15.2552C75.2735 17.9648 79.3347 21.5619 82.5849 25.841C84.9175 28.9121 86.7997 32.2913 88.1811 35.8758C89.083 38.2158 91.5421 39.6781 93.9676 39.0409Z" fill="currentFill"></path>
                                        </svg>
                                    </div>
                                )}
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>
    )
}
