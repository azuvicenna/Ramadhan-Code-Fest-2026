export type Question = {
	id: string;
	question: string;
	options: { label: string; score: number }[];
};

export const questions: Question[] = [
	{
		id: "need",
		question: "Apakah ini kebutuhan atau keinginan?",
		options: [
			{ label: "Kebutuhan penting", score: 2 },
			{ label: "setengah kebutuhan", score: 1 },
			{ label: "Keinginan", score: -1 },
			{ label: "Impuls doang", score: -2 },
		],
	},
	{
		id: "frequency",
		question: "Seberapa sering akan dipakai?",
		options: [
			{ label: "Setiap hari", score: 2 },
			{ label: "Kadang-kadang", score: 1 },
			{ label: "Jarang", score: 0 },
		],
	},
	{
		id: "budget",
		question: "Apakah budget aman?",
		options: [
			{ label: "Sangat aman", score: 2 },
			{ label: "Aman", score: 1 },
			{ label: "Pas-pasan", score: 0 },
			{ label: "Tidak aman", score: -1 },
			{ label: "Sangat tidak aman", score: -2 },
		],
	},
	{
		id: "emotion",
		question: "Apakah kamu lagi emosional?",
		options: [
			{ label: "Sangat tidak emosional", score: 2 },
			{ label: "Tidak emosional", score: 1 },
			{ label: "netral", score: 0 },
			{ label: "emosional", score: -1 },
			{ label: "Sangat emosional", score: -2 },
		],
	},
	{
		id: "alternative",
		question: "Apakah ada alternatif?",
		options: [
			{ label: "Ada dan jauh lebih baik", score: -2 },
			{ label: "Ada alternatif mirip", score: -1 },
			{ label: "Tidak yakin ada alternatif", score: 0 },
			{ label: "Tidak ada alternatif", score: 1 },
		],
	},
];
