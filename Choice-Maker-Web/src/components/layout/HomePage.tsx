import { useNavigate } from "react-router-dom";

export default function HomePage() {
	const navigate = useNavigate();

	const handleClick = () => {
		navigate("/quiz/1");
	};

	return (
		<main className="h-screen w-screen flex items-center justify-center">
			<div className="text-center">
				<h1 className="text-2xl font-bold uppercase">
					Choice Maker Web{" "}
				</h1>
				<p className="text-sm font-normal text-gray-500">
					Pakai web ini jika ingin membeli barang namun ragu
				</p>
				<button
					onClick={handleClick}
					className="px-4 py-1 rounded-md border my-5 cursor-pointer transition-colors duration-150 ease-in-out hover:bg-black hover:text-white active:scale-95">
					Start
				</button>
			</div>
		</main>
	);
}
